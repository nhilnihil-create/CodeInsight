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
    int n,k; cin>>n>>k;
    ld ans=0.0,res=0;
    vi a(n+1);
    for (int i=1;i<=n;i++) {
        cin>>a[i]; a[i]++; 
        if (i<=k) ans += a[i]/2.0;
    }
    res=ans;
    for (int i=k+1;i<=n;i++){
        ans -= a[i-k]/2.0;
        ans += a[i]/2.0;
        res = max(res,ans);
    }
    cout.precision(20);
    cout << res << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
