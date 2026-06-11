#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <bits/stdc++.h>

#define ll long long
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f first
#define s second
#define INF 0x3f3f3f3f3f3f3f3f
#define pnt complex <double> 
#define pi acos(-1)
#define mod 1000000007

using namespace std;

ll fact[1000006], inv[1000006];

ll fp(ll base, ll exp) {
	if (exp == 0)
		return 1;
	ll ans = fp(base, exp / 2);
	ans = (ans * ans) % mod;
	if (exp % 2 != 0)
		ans = (ans * (base % mod)) % mod;
	return ans;
}

void calcFacAndInv(ll n) {
	fact[0] = inv[0] = 1;
	for (ll i = 1; i <= n; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
		inv[i] = fp(fact[i], mod - 2);
	}
}

ll ncr(ll n, ll r) {
	return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll npr(ll n, ll r) {
	return (fact[n] * inv[n - r]) % mod;
}
double dot(pnt a, pnt  b) {
	return (conj(a)*b).real();
}

int main() {

	HS
	calcFacAndInv(1000000);
	int n, k;
	cin >> n >> k;
	int  blue = k, red = n - k;
	
	for (int i = 1; i <= k; i++) {

		if (red + 1 - i < 0) {
			cout << 0 << endl;
			continue;
		}
		ll ans = (ncr(blue - 1, i - 1) % mod * ncr( red + 1, i) % mod) % mod;
		cout << ans << endl;
	}
	return 0;
}