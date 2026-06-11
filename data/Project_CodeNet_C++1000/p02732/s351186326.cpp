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
    map <int,int> m;
    int n,ans=0; 
    cin>>n; 
    vi a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i] ; 
        m[a[i]]++;
    }
    for (auto it: m) ans += (it.ss*(it.ss-1))/2 ; 
    for (int i=0;i<n;i++){
        int h=m[a[i]];
        cout << (ans-((h*(h-1))/2)+((h-1)*(h-2))/2) << endl; 
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
