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
    int n,m,x; cin>>n>>m>>x; 
    int a[n][m+1],ans=1000000000;
    for (int i=0;i<n;i++)
        for (int &j: a[i]) cin>>j;
    for (int i=0;i<(1<<n);i++){
        vi h(m+1,0); int cnt=0;
        for (int j=0;j<n;j++){
            if ((i>>j)&1){
                for (int k=0;k<=m;k++){
                    if (k==0) cnt += a[j][0];
                    else h[k] += a[j][k];
                }
            }
        }
        if (cnt<ans){
            bool flag=true;
            for (int j=1;j<=m;j++){
                if (h[j]<x) flag=false;
            }
            if (flag) ans=cnt;
        }
    }
    cout << ((ans==1000000000)?"-1":to_string(ans)) << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
