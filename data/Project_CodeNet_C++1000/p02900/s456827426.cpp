// #include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define exf(x)	 for(auto&& tmp : x) { cout << tmp << endl; }	// 拡張for
#define PI 3.14159265358979323846264338327950288
const int MOD{ int(1e9 + 7) };	// = 1000000007
const int inf{ 2100000000 };	// = 2100000000 (MAX:2147483647)
typedef long long ll;
using namespace std;

// -------------------------------------------------- //
// ------------------ ここから本編 ------------------ //
// -------------------------------------------------- //

set<ll> prime_set; // [0]2, [1]3, [2]5, [3]7, ... のように代入される
void PRIME_SET(ll x) {
	if (x <= 1)return;

	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			PRIME_SET(i);
			PRIME_SET(ll(x / i));
			return;
		}
	}
	prime_set.insert(x);
	return;
}

int main(void) {

	ll A, B; cin >> A >> B;

	prime_set.clear();
	PRIME_SET(A);
	set<ll> a_map = prime_set;
	
	prime_set.clear();
	PRIME_SET(B);
	set<ll> b_map = prime_set;

	ll ans = 1;
	for (auto x : a_map) {
		if (find(b_map.begin(), b_map.end(), x) != b_map.end()) ans++;
	}
	cout << ans << endl;
	return 0;
}
