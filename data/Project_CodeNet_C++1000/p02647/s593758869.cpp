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
    int  n, k ; 
    cin >> n >> k ; 
    vi  a(n+2) ; 
    for (int i=1;i<=n;i++) cin >> a[i] ; 
    for (int i=1;i<=k;i++){
        bool ok=true;
        vi pref(n+2); 
        for (int i=1;i<=n;i++){ 
            int l = max(0LL, i-a[i]) ; 
            int r = min(n+1, i+a[i]+1) ; 
            pref[l]++; pref[r]--;
        } 
        for (int i=1;i<=n;i++) pref[i] += pref[i-1] ; 
        for (int i=1;i<=n;i++) if (pref[i]<n) ok=false; 
        a = pref;
        if (ok) break ; 
    }
    for (int i=1;i<=n;i++) cout << a[i] << " "; 
    cout << endl ; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
