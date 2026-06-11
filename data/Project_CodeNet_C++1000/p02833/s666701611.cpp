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

inline void solve(){ 
    int n,ans=0; 
    cin >> n ; 
    if (n&1^1) { 
    	while (n>9){ 
    		ans += n/10; 
    		n /= 5; 
    	} 
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
200->40->8->5

20+4+0+0=24
*/