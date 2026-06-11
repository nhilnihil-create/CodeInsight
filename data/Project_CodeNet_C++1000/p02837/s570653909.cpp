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
    int n; cin>>n; 
    int a[n];
    vector <vector<pii>> xy(n+1);
    for (int i=0;i<n;i++){
        cin >> a[i]; 
        for (int j=0;j<a[i];j++){
            int x,y; cin>>x>>y;
            xy[i].emplace_back(x-1,y);
        }
    }
    int ans=0;
    for (int  bit=0 ; bit < (1<<n) ; bit++){
        bool ok=true;
        for (int i=0;i<n;i++){
            bool cur=true;
            if ( bit & (1<<i) ){ 
                for (int j=0;j<sz(xy[i]);j++){
                    if ( ( ( bit >> xy[i][j].ff ) & 1) != xy[i][j].ss ) ok = false; 
                }
            }
            if (!ok) break;
        }
        if (ok) ans = max(ans,(int)__builtin_popcount(bit));
    }
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
