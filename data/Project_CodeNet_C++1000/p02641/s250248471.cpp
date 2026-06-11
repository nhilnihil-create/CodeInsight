#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>
#pragma GCC optimize ("Ofast")

#define repk(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n)  for(int i=0;i<=(n);++i)
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define for1(i,n)  for(int i=1;i<(n);++i)
#define FORR(x,arr) for(auto& x:arr)
#define SZ(a) int((a).size())
#define ll long long
#define ld long double
#define point pair<double,double>
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define vl vector<ll>
const int  inf = INT_MAX;
const int MOD = 1000000007;
const int N = 100100;

using namespace std;


void sol() {
	int x, n; cin >> x >> n;
	int mn = inf;
	set<int> p;
	rep (i, 0, n) {
		int a;
		cin >> a;
		p.insert(a);
	}
	int ans = 0;
	rep(i, 0, 102) {
		if (!p.count(i)) {
			int d = abs(i - x);
			if (d < mn)
				ans = i, mn = d;
		}
	}
	cout << ans << '\n';




}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int t = 1; // cin >> t;
	while (t--)
		sol();
	return 0;
}
