#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll MOD = 1000000007;

int main() {
	ll N;
	cin >> N;

	vector <ll> A(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> A[ii];
	}

	ll ans = 0;
	for (ll keta = 0; keta < 61; ++keta){
		ll n0 = 0;
		ll n1 = 0;
		for (int ii = 0; ii < N; ++ii){
			if (A[ii] & 1){
				n1++;
			} else {
				n0++;
			}
			A[ii] /= 2;
		}
		ll base = (1LL<<keta) % MOD;
		ll ptn = (n0*n1) % MOD;
		ans = (ans + ptn*base) % MOD;
	}

	cout << ans << "\n";

	return 0;
}
