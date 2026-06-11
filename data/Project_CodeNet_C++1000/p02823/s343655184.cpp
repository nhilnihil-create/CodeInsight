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

inline void solve() { 
	int  n,a,b,ans=0;
	cin >> n >> a >> b ; 
	if((b-a)&1^1) ans = (b-a)/2;
	else ans = min(n-b,a-1)+1+(b-a)/2;
	cout << ans << endl;
} 

signed main()
{
	int n = 1;
	// cin >> n;
	while (n--)
		solve();
	return 0;
}
/*

*/
