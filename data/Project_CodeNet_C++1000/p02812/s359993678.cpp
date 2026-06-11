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
R"X(33
ABCCABCBABCCABACBCBBABCBCBCBCABCB)X";
stringstream iss{text};
#endif

ll cnt;
int main( ) {
	cin.tie(0);	ios::sync_with_stdio(0);
	ll N; iss >> N;
	string s; iss >> s;
	for (ll i = 0; i < N - 2; ++i) {
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') ++cnt;
	}
	cout << cnt << "\n";
}
