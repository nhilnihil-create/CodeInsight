
#include <bits/stdc++.h>
//#include <atcoder/all>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007; //998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}

static void A();

int main()
{
	A();
	fflush(stdout);
	return 0;
}

static void A()
{
	int S;
	get(S);

	std::vector<LLONG> dp(S + 1, 0);
	dp[0] = 1;

	for (int i = 3; i <= S; i++) {
		dp[i] = (dp[i - 3] + dp[i - 1]) % MOD_NUM;
	}
	printf("%lld\n", dp[S]);
} 
