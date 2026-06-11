/*---Bismillahir Rahmanir Rahim---*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define mod 998244353
#define int long long
#define ld long double
#define pb push_back
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define pii pair<int, int>
using namespace std; 

int fact(int n){
	if (n<=1) return 1;
	return  n*fact(n-1);
}

inline void solve()
{
	int mn=1000000,ans=0,n;
	cin >> n ; 
	while (n--) {
		int  a; cin >> a;
		if (a<=mn) ans++;
		mn = min(mn,a);
	}
	cout << ans << endl ; 
}

signed main()
{
	int t=1; // cin>>t;
	while(t--) solve();
	return 0;
}

/*
5
4 2 5 1 3

*/
