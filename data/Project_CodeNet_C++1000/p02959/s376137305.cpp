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
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
using namespace std;

inline void solve(){ 
    int n,ans=0; cin>>n; 
    vi mon(n+3),hero(n+3); 
    for (int i=1;i<=n+1;i++) cin >> mon[i] ; 
    for (int i=1;i<=n;i++) cin >> hero[i] ; 
    for (int i=1;i<=n;i++){ 
        if ( mon[i]<=hero[i] ) { ans += mon[i], hero[i]-=mon[i]; } 
        else if ( mon[i]>=hero[i] ) { ans += hero[i],hero[i]=0; } 
        if ( mon[i+1]<=hero[i] ) { ans += mon[i+1], mon[i+1]=0; } 
        else if ( mon[i+1] >= hero[i] ) { ans += hero[i],mon[i+1]-=hero[i]; } 
    } 
    cout << ans << endl; 
} 
 
signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
