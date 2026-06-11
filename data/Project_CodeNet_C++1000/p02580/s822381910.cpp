#pragma GCC optimize ("O3")

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>
#include <numeric>
#include <list>
using namespace std;

using QWORD  = uint64_t;
using SQWORD = int64_t;
using DWORD  = uint32_t;
using SDWORD = int32_t;
using WORD   = uint16_t;
using SWORD  = int16_t;
using BYTE   = uint8_t;
using SBYTE  = int8_t;
using DOUBLE = double;
using LDOUBLE = long double;
using FLOAT  = float;

#define MIN_SDWORD (-2147483648)
#define MAX_SDWORD (2147483647)
#define MIN_SBYTE (-128)
#define MAX_SBYTE (127)

#define MIN_SQWORD (0x8000000000000000)
#define MAX_SQWORD (0x7FFFFFFFFFFFFFFF)

#define MAX_QWORD  (0xFFFFFFFFFFFFFFFF)
#define MAX_DWORD  (0xFFFFFFFF)
#define MAX_WORD   (0xFFFF)
#define MAX_BYTE   (0xFF)

#define MAX_DOUBLE      (1.0e+308)
#define DOUBLE_EPS      (1.0e-12)
#define MIN_DOUBLE_N    (-1.0e+308)

#define ArrayLength(a)  (sizeof(a) / sizeof(a[0]))

static inline DOUBLE MAX(DOUBLE a, DOUBLE b) { return a > b ? a : b; }
static inline QWORD MAX(QWORD a, QWORD b) { return a > b ? a : b; }
static inline DWORD MAX(DWORD a, DWORD b) { return a > b ? a : b; }
static inline SDWORD MAX(SDWORD a, SDWORD b) { return a > b ? a : b; }
static inline DOUBLE MIN(DOUBLE a, DOUBLE b) { return a < b ? a : b; }
static inline QWORD MIN(QWORD a, QWORD b) { return a < b ? a : b; }
static inline DWORD MIN(DWORD a, DWORD b) { return a < b ? a : b; }
static inline SDWORD MIN(SDWORD a, SDWORD b) { return a < b ? a : b; }

#define BYTE_BITS   (8)
#define WORD_BITS   (16)
#define DWORD_BITS  (32)
#define QWORD_BITS  (64)

static inline void inputStringSpSeparated(char *pcStr)
{
    char *pcCur = pcStr;
    for (;;) {
        char c = getchar();
        if (('\n' == c) || (EOF == c) || (' ' == c)) {
            break;
        }
        *pcCur = c;
        pcCur++;
    }
    *pcCur = '\0';
}

static inline void inputString(char *pcStr)
{
    char *pcCur = pcStr;
    for (;;) {
        char c = getchar();
        if (('\n' == c) || (EOF == c)) {
            break;
        }
        *pcCur = c;
        pcCur++;
    }
    *pcCur = '\0';
}


static inline SQWORD inputSQWORD(void)
{
    SQWORD sqNumber = 0;
    SQWORD sqMultiplier = 1;
    bool bRead = false;
    for (;;) {
        char c = getchar();
        if (!bRead) {
            if ('-' == c) {
                sqMultiplier = -1;
            }
        }
        if (('0' <= c) && (c <= '9')) {
            sqNumber *= 10LL;
            sqNumber += (SQWORD)(c - '0');
            bRead = true;
        } else {
            if (bRead) {
                return sqNumber * sqMultiplier;
            }
        }
    }
}


static inline SDWORD inputSDWORDPlus(void)
{
    SDWORD lNumber = 0;
    SDWORD lMultiplier = 1;
    bool bRead = false;
    for (;;) {
        char c = getchar();
        if (('0' <= c) && (c <= '9')) {
            lNumber *= 10;
            lNumber += (c - '0');
        } else {
            return lNumber * lMultiplier;
        }
    }
}


/*----------------------------------------------*/

#define MAX_H   (300000)
#define MAX_W   (300000)


int main(void)
{
    SDWORD lH = inputSDWORDPlus();
    SDWORD lW = inputSDWORDPlus();
    SDWORD lM = inputSDWORDPlus();

    static SDWORD s_alCntH[MAX_H];
    static SDWORD s_alCntW[MAX_W];
    SDWORD lMaxH = 0;
    SDWORD lMaxW = 0;

    vector<pair<SDWORD, SDWORD>> vpairlTgtPos;

    for (SDWORD lIdx = 0 ; lIdx < lM; lIdx++) {
        SDWORD lTgtH = inputSDWORDPlus() - 1;
        SDWORD lTgtW = inputSDWORDPlus() - 1;

        s_alCntH[lTgtH]++;
        s_alCntW[lTgtW]++;

        lMaxH = max(lMaxH, s_alCntH[lTgtH]);
        lMaxW = max(lMaxW, s_alCntW[lTgtW]);

        vpairlTgtPos.emplace_back(make_pair(lTgtH, lTgtW));
    }

    SDWORD lCntMaxH = 0;
    SDWORD lCntMaxW = 0;
    for (SDWORD lIdx = 0; lIdx < lH; lIdx++) {
        if (s_alCntH[lIdx] == lMaxH) {
            lCntMaxH++;
        }
    }
    for (SDWORD lIdx = 0; lIdx < lW; lIdx++) {
        if (s_alCntW[lIdx] == lMaxW) {
            lCntMaxW++;
        }
    }

    SQWORD sqCntMaxPos = 0;
    SDWORD lMaxHW = lMaxH + lMaxW;
    for (auto pos: vpairlTgtPos) {
        if (s_alCntH[pos.first] + s_alCntW[pos.second] == lMaxHW) {
            sqCntMaxPos++;
        }
    }

    if (sqCntMaxPos == (SQWORD)lCntMaxH * (SQWORD)lCntMaxW) {
        printf("%ld\n", lMaxHW - 1);
    } else {
        printf("%ld\n", lMaxHW);
    }

    return 0;
}
