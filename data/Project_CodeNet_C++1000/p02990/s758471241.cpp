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
#define   mod  1000000007
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

int bigmod(int a,int p,int m){
    if (p==0) return 1;
    if (p&1){
        int p1=a%mod;
        int p2 = bigmod(a,p-1,m);
        return (p1*p2)%mod;
    }
    int p1=bigmod(a,p/2,m);
    return (p1*p1)%m;
}

int ncr(int n,int r){
    int a=1,b=1;
    for (int i=1;i<=r;i++){
        a = (a*(n-i+1))%mod;
        b = (b*i)%mod;
    }
    return (a*bigmod(b,mod-2,mod))%mod;
}

inline void solve(){
    int  n, k; cin >> n >> k ; 
    int spot = n-k+1 ; 
    int  ans = 0 ; 
    for (int i=1;i<=k;i++){
        cout << ((ncr(spot,i)*ncr(k-1,i-1))%mod) << endl;
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
