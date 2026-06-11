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

	int x; cin >> x;
	cout << (360 / __gcd(x, 360));
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1; // cin >> t;
	while (t--)
		sol();
	return 0;
}