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
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
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

int  dp[1001][20005] ; 

inline void solve(){ 
    fill(dp[0]+1,dp[0]+20005,1000000000);
    dp[0][0] = 0 ; 
    int  health , n ; 
    cin >> health >> n ; 
    for (int i=1;i<=n;i++){ 
        int  a, b; 
        cin >> a >> b; 
        for (int j=0;j<=20000;j++){ 
            if(a > j) dp[i][j] = dp[i-1][j] ; 
            else dp[i][j] = min(dp[i-1][j],dp[i][j-a]+b); 
        } 
    } 
    cout << *min_element(dp[n]+health,dp[n]+20001) << endl; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
