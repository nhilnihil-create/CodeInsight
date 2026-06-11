#ifdef __GNUC__
#pragma GCC target("avx2")
#pragma GCC optimize ("O20")
#pragma GCC optimize ("tree-vectorize")
#pragma GCC optimize("unroll-loops")
#define iss std::cin
#endif
#include "bits/stdc++.h"
#define rep(i, times) for(ll i = 0; i < (times); ++i)
using ll = int_fast64_t; using namespace std;

#ifndef __GNUC__
string text =
R"X(136)X";
stringstream iss{text};
#endif

ll cnt;
inline bool  oddQ(ll &b) { return (b & 1); }
int main( ) {
	cin.tie(0);	ios::sync_with_stdio(0);
	ll N; iss >> N;
	for (ll i = 1; i <= N; ++i) {
		if ((ll(log10(i)) + 1) & 1) ++cnt;
	}
	cout << cnt << "\n";
}
