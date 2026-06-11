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

int fun(int n){
    return ((n*(n-1))/2)%1000000007;
}

inline void solve(){
    map <int,int> oc;
    int n,k,ans=0; 
    cin>>n>>k; 
    vi a(n),b(n),help(n,0);
    for (int &i: a) cin>>i;
    for (int i=0;i<n;i++){
        int b=0,f=0;
        for (int j=i+1;j<n;j++) if (a[i]>a[j]) b++;
        for (int j=0;j<i;j++) if (a[i]>a[j]) f++;
        ans = (ans  + ((f+b)*fun(k)) + (b*k))%1000000007;
    }
    cout << ans << endl;
    return;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
