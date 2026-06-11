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
    vi  a(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    a[1]--; bool ok=true;
    for (int i=2;i<=n;i++){
        if (a[i]<a[i-1]) ok=false;
        if (a[i]-1>=a[i-1]) a[i]--;
    }
    if (ok) cout << "Yes" << endl; 
    else cout << "No" << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
