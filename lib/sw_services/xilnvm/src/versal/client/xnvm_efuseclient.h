/******************************************************************************
* Copyright (c) 2021 Xilinx, Inc.  All rights reserved.
* Copyright (c) 2022-2023, Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
*******************************************************************************/

/*****************************************************************************/
/**
*
* @file versal/client/xnvm_efuseclient.h
* @addtogroup xnvm_efuse_versal_client_apis XilNvm eFUSE Versal Client APIs
* @{
* @cond xnvm_internal
* This file Contains the client function prototypes, defines and macros for
* the eFUSE programming and read.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -------------------------------------------------------
* 1.0   kal  07/29/21 Initial release
*       kpt  08/27/21 Added client API's to support puf helper data efuse
*                     programming
*       kpt  03/16/22 Removed IPI related code and added mailbox support
* 3.1   skg  10/04/22 Added SlrIndex Constants
*
* </pre>
*
* @note
*
* @endcond
******************************************************************************/

#ifndef XNVM_EFUSECLIENT_H
#define XNVM_EFUSECLIENT_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#include "xil_types.h"
#include "xnvm_defs.h"
#include "xnvm_mailbox.h"

/************************** Constant Definitions *****************************/

/**< Slr index shift constant*/
#define XNVM_SLR_INDEX_SHIFT (6U)

/**< SlrIndexs constants*/
#define XNVM_SLR_INDEX_0 (0U) /**< SLR Index 0*/
#define XNVM_SLR_INDEX_1 (1U) /**< SLR Index 1*/
#define XNVM_SLR_INDEX_2 (2U) /**< SLR Index 2*/
#define XNVM_SLR_INDEX_3 (3U) /**< SLR Index 3*/

/**< PPK Read Offsets constants*/
#define XNVM_EFUSE_PPK_READ_START XNVM_EFUSE_PPK0 /**<Start value of ppk0*/
#ifdef XNVM_EN_ADD_PPKS
#define XNVM_EFUSE_PPK_READ_END XNVM_EFUSE_PPK4
#else
#define XNVM_EFUSE_PPK_READ_END XNVM_EFUSE_PPK2 /**<Start value of ppk2*/
#endif

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/
#define XNVM_WORD_LEN		(4U) /**< Word length*/

/************************** Function Prototypes ******************************/
int XNvm_EfuseWrite(XNvm_ClientInstance *InstancePtr, const u64 DataAddr);
int XNvm_EfuseWriteIVs(XNvm_ClientInstance *InstancePtr, const u64 IvAddr, const u32 EnvDisFlag);
int XNvm_EfuseRevokePpk(XNvm_ClientInstance *InstancePtr, const XNvm_PpkType PpkRevoke, const u32 EnvDisFlag);
int XNvm_EfuseWriteRevocationId(XNvm_ClientInstance *InstancePtr, const u32 RevokeId, const u32 EnvDisFlag);
int XNvm_EfuseWriteUserFuses(XNvm_ClientInstance *InstancePtr, const u64 UserFuseAddr, const u32 EnvDisFlag);
int XNvm_EfuseReadIv(XNvm_ClientInstance *InstancePtr, const u64 IvAddr, const XNvm_IvType IvType);
int XNvm_EfuseReadRevocationId(XNvm_ClientInstance *InstancePtr, const u64 RevokeIdAddr, const XNvm_RevocationId RevokeIdNum);
int XNvm_EfuseReadUserFuses(XNvm_ClientInstance *InstancePtr, const u64 UserFuseAddr);
int XNvm_EfuseReadMiscCtrlBits(XNvm_ClientInstance *InstancePtr, const u64 MiscCtrlBits);
int XNvm_EfuseReadSecCtrlBits(XNvm_ClientInstance *InstancePtr, const u64 SecCtrlBits);
int XNvm_EfuseReadSecMisc1Bits(XNvm_ClientInstance *InstancePtr, const u64 SecMisc1Bits);
int XNvm_EfuseReadBootEnvCtrlBits(XNvm_ClientInstance *InstancePtr, const u64 BootEnvCtrlBits);
int XNvm_EfuseReadPufSecCtrlBits(XNvm_ClientInstance *InstancePtr, const u64 PufSecCtrlBits);
int XNvm_EfuseReadOffchipRevokeId(XNvm_ClientInstance *InstancePtr, const u64 OffChidIdAddr, const XNvm_OffchipId OffChipIdNum);
int XNvm_EfuseReadPpkHash(XNvm_ClientInstance *InstancePtr, const u64 PpkHashAddr, const XNvm_PpkType PpkHashType);
int XNvm_EfuseReadDecOnly(XNvm_ClientInstance *InstancePtr, const u64 DecOnlyAddr);
int XNvm_EfuseReadDna(XNvm_ClientInstance *InstancePtr, const u64 DnaAddr);
#ifdef XNVM_ACCESS_PUF_USER_DATA
int XNvm_EfuseWritePufAsUserFuses(XNvm_ClientInstance *InstancePtr, u64 PufUserFuseAddr);
int XNvm_EfuseReadPufAsUserFuses(XNvm_ClientInstance *InstancePtr, const u64 PufUserFuseAddr);
#else
int XNvm_EfuseWritePuf(XNvm_ClientInstance *InstancePtr, const u64 PufHdAddr);
int XNvm_EfuseReadPuf(XNvm_ClientInstance *InstancePtr, const u64 PufHdAddr);
#endif

/************************** Variable Definitions *****************************/

#ifdef __cplusplus
}
#endif

#endif  /* XNVM_EFUSECLIENT_H */
