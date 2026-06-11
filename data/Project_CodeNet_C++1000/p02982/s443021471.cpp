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
    int n,r; cin>>n>>r;
    int a[n][r],ans=0;
    for (int i=0;i<n;i++){
        for (int &j: a[i]) cin>>j;
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++) {
            int d=0;
            for (int k=0;k<r;k++){
                d += (a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
            }
            // do some calculation....
            int sq=sqrt(d);
            if (sq*sq==d) ans++;
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
