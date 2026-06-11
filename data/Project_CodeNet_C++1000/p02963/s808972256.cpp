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
    int s,h=1000000000; cin>>s; 
    int x2= (s+h-1)/h;
    int y2=h*x2-s;
    cout << "0 0 1 1000000000 " << x2 << " " << y2 << endl;
    // cout << abs(1*y2-x2*1000000000) << endl; 
    return; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
