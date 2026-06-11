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
    map <int,int> cnt;
    int stair,n,a; cin>>stair>>n; 
    vi res(stair+1,0);
    for (int i=0;i<n;i++) {
        cin>>a; 
        cnt[a]++;
    }
    res[0]=1;
    if (!cnt[1]) res[1]=1;
    for (int i=2;i<=stair;i++){
        if (!cnt[i]) res[i] =  res[i-1]+res[i-2]; 
        res[i] = res[i]%1000000007;
    } 
    cout << res[stair] << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
/*
100 5
1
23
45
67
89
output: 608200469

6 1
3
output: 4

*/