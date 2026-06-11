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
#include <functional>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end()
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){ 
    int  n, m, ans = 0 ; 
    cin >> n >> m ; 
    vector < pair<int, int> > ab ; 
    vector <int>  ocupy ; 
    for (int  i = 1 ; i <= m; i++) ocupy.pb(i); 
    for (int  i = 0 ; i < n ; i++) {
        int a,b ; cin>>a>>b;
        if (a>m) continue;
        ab.emplace_back(b,a) ; 
    }
    sort(all(ab)) ; 
    for (int  i = sz(ab)-1 ; i >= 0 ; i--) { 
        int k = ab[i].ss ; 
        auto  it = lower_bound(ocupy.begin(), ocupy.end(), k ) ; 
        if (it != ocupy.end()) {
            int in =  it - ocupy.begin() ; 
            ocupy.erase( ocupy.begin() + in ) ; 
            ans += ab[i].ff ; 
        }
    }
    co (ans) ; 
}
// https://atcoder.jp/contests/abc137/tasks/abc137_d 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
