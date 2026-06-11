#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
//vector<vector<ll>> data(3, vector<ll>(4));
//vector<ll> data(N);
//str s = to_string(i);
//int i = c - '0'
//sort(data.begin(), data.end());
//reverse(data.begin(), data.end());
//data.erase(unique(data.begin(), data.end()), data.end());
//str.substr(n)//n番以降スライス
//str.substr(n,m)//n番以降m文字スライス
//str.erase(n)//n番以降削除
//str.erase(n,m)//n番以降m文字削除
typedef long long ll;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define PB push_back
#define MOD 1000000007
using namespace std;

ll powmod(ll x, ll y) {
	ll s=1;
	REP(i, y) {
		s = s * x % MOD;
	}
	return s;
}

int main() {
	ll N;
	cin >> N;

	ll s;
	s = powmod(10, N) - 2 * powmod(9, N) + powmod(8, N);
	if (s % MOD >= 0) s %= MOD;
	else s = s % MOD + MOD;
	cout << s << endl;
}