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


int bigmod(int a,int p){
    if (p==0) return 1;
    if (p&1){
        int p1=a%mod;
        int p2 = bigmod(a,p-1)%mod;
        return (p1*p2)%mod;
    }
    int p1=bigmod(a,p/2)%mod;
    return (p1*p1)%mod;
}

int fermat(int n,int a){
    int x=1,y=1;
    for (int i=1;i<=a;i++){
        y = (y*i)%mod;
        x = (x*(n-i+1))%mod;
    }
    return (x*bigmod(y,mod-2))%mod; 
}

inline void solve(){
    int n,a,b; 
    cin>>n>>a>>b; 
    cout << ((bigmod(2,n)-fermat(n,a)-fermat(n,b)-1)+(6LL*mod))%mod << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
