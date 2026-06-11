#ifdef __GNUC__
#pragma GCC target("avx2")
#pragma GCC optimize ("O25")
#pragma GCC optimize ("tree-vectorize")
#pragma GCC optimize("unroll-loops")
#define iss std::cin
#endif
#include "bits/stdc++.h"
#define rep(i, times) for(ll i = 0; i < (times); ++i)
#define p(x) (cout << x << "\n")
using ll = long long; using ld = long double; using namespace std;
int main( ) {
	cin.tie(0);	ios::sync_with_stdio(0);
	//class CountOrder a; a.procedures( );
	ll A, B;
	cin >> A >> B;
	p(A * B);

}