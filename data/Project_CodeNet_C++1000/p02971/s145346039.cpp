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
    int n; cin>>n; 
    vi a(n),b(n);
    for (int i=0;i<n;i++){
        cin >> a[i] ; 
        b[i] = a[i] ; 
    }
    sort(a.begin(), a.end());
    int f=a[n-1],s=a[n-2];
    for (int i=0;i<n;i++){
        if (b[i]!=f) cout << f << endl;
        else cout << s << endl;
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
