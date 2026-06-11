/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  (int)(1e9+7)
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){ 
    int n; cin>>n; 
    vi a(n+1),dp(n,0); 
    dp[0] = 3;
    int ans = 1 ; 
    for (int i=1;i<=n;i++) cin >> a[i] ; 
    for (int  i=1 ; i<=n ; i++) { 
        ans = (ans*(dp[a[i]]))%mod;
        dp[a[i]]--; dp[a[i]+1]++;
    } 
    cout << ans << endl; 
} 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
/*

0 0 0 1 1 1 


*/
