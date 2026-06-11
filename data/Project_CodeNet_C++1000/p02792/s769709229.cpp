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
    int f=n%10,s=0,h=n;
    while(n){
        s = n%10;
        n /= 10;
    }
    if (f==0) return 0;
    if (f != s) return f*10+s;
    return f;
}

int helper (int n){
    int s=0;
    while (n){
        s = s*10 + (n%10) ; 
        n /= 10 ; 
    }
    return s;
}

inline void solve(){
    int n; cin>>n; 
    map <int,int> cnt;
    for (int i=1;i<=n;i++) { 
        cnt[fun(i)]++; 
    } 
    int  ans = 0 ; 
    for (auto &it: cnt){
        if (it.ff==0) continue;
        int x=it.ff;
        if (x<=9) ans += it.ss*it.ss; 
        else {
            int h= helper(x);
            ans += it.ss*cnt[h];
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
