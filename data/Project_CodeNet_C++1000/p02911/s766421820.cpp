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
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
using namespace std;

inline void solve(){ 
    int n,k,q,i=0;
    cin>>n>>k>>q;
    vector <int> a(n+1,k);
    //for (int &i: a) cout << i << " ";
    while (i++<q){
      int x; cin>>x;
      a[x]++;
    }
    for (int i=1;i<=n;i++){
        if (a[i]-q>0) puts("Yes");
        else puts("No");
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
