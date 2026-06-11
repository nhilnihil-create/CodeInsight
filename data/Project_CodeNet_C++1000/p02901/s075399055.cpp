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
#include <functional>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end() 
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){ 
    int  n, m ; 
    cin >> n >> m ; 
    vi  a(m),b(m) ; 
    vector <vi>  key(m+1, vi(15, 0)) ; 
    for (int i=0;i<m;i++){
    	cin >> a[i] >> b[i] ; 
    	for (int j=0;j<b[i];j++) {
    		cin >> key[i][j] ; 
    		key[i][j]-- ; 
    	}
    }
    vi  dp( 1<<n, 1e9 ) ; 
    dp[0] = 0 ; 
    for (int i=0;i<m;i++){ 
    	int now = 0 ; 
    	for (int j=0;j<b[i];j++){ 
    		now |= (1 << key[i][j] ) ; 
    	} 
    	if (i == 0) dp[now] = a[i] ; 
    	for (int  bit = 0; bit < (1<<n) && i>0 ; bit++ ) { 
    		dp[bit | now] = min(dp[bit | now], dp[bit]+a[i]) ; 
    	} 
    } 
    if (dp[ (1<<n) - 1 ] == 1e9) dp[(1<<n)-1] = -1 ; 
    co (dp[(1<<n)-1]) ; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
