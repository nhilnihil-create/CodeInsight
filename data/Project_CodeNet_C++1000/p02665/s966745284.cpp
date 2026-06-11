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
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){
    int n,total=0,ans = 0 ; 
    cin>>n; 
    bool  ok = true ; 
    vi a(n+1); 
    for (int  i=0 ; i<=n ; i++ ) { 
    	cin >> a[i] ; 
    	total += a[i] ; 
    } 
    for ( int i = 0,cur = 1 ; i <= n; i++ ) { 
    	ans += cur;
    	if (a[i] > cur) ok = false ; 
    	cur -= a[i];
    	total -= a[i]; 
    	if (cur *2 > total ) cur = total;
    	else cur *= 2;
    } 
    cout << (ok?to_string(ans):to_string(-1)) << endl ; 
}
/*
3
0 1 1 2
*/

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
