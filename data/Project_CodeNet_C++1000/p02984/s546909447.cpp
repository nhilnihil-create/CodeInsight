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
    int n,ans=0; cin>>n; 
    vi a(n);
    for (int i=0;i<n;i++) {
        cin>>a[i];
        if (i&1) ans -= a[i];
        else ans += a[i];
    }
    cout << ans << " ";
    for (int i=0;i<n-1;i++){
        int h=a[i]-(ans/2);
        ans = h*2;
        cout << ans << " ";
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}

/*
5
3 8 7 5 5
2 4 12 2 8

*/