
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef unsigned long long ULLONG;
typedef long long LLONG;

template <class _T> static _T tp_abs(const _T& a) {
	return ((a < 0) ? (a * -1) : a);
}
template <class _T> static _T tp_min(_T a, _T b) {
	return a < b ? a : b;
}
template <class _T> static _T tp_max(_T a, _T b) {
	return a > b ? a : b;
}
template <class _T> static _T tp_modpow(_T a, _T n, _T mod = (_T)1) {
	_T ans = 1;
	while (n > 0) {
		if (n & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}

template <class _T> static _T tp_modfact(_T n, _T k, _T mod = (_T)1) {
	_T count = 0;
	_T ans = 1;

	while (count < k) {
		ans = ans * (n - count) % mod;
		count++;
	}
	return ans;
}
template<class _T> static void getint(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}
static void getstring(char* buff) {
	if (scanf(" %s", buff) < 0) {
		printf("getstr error!\n");
	}
}
static const long long MOD_NUM = 1000000007LL;

static void D_task();
#if 1
int main()
{
	D_task();
	fflush(stdout);
	return 0;
}
#endif


static void D_task()
{
	LLONG N, A, B;
	getint<LLONG>(N, A, B);
	
	LLONG total = tp_modpow<LLONG>(2, N, MOD_NUM) % MOD_NUM - 1;
	LLONG aCnt =
		tp_modfact<LLONG>(N, A, MOD_NUM)
		* tp_modpow<LLONG>(
			tp_modfact<LLONG>(A, A, MOD_NUM),
			MOD_NUM - 2,
			MOD_NUM
			)
		% MOD_NUM;
	LLONG bCnt = tp_modfact<LLONG>(N, B, MOD_NUM)
		* tp_modpow<LLONG>(
			tp_modfact<LLONG>(B, B, MOD_NUM),
			MOD_NUM - 2,
			MOD_NUM
			)
		% MOD_NUM;
	LLONG ans = (total - aCnt - bCnt) % MOD_NUM;
	printf("%lld\n", (ans < 0) ? ans + MOD_NUM : ans);
}
