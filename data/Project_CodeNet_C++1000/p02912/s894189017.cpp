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
    int n,m; cin>>n>>m; 
    priority_queue<int> pq;
    for (int i=0;i<n;i++){
        int a; cin>>a; 
        pq.push(a);
    }
    while (m--){
        int helper=pq.top();
        pq.pop();
        helper /= 2;
        pq.push(helper);
    }
    int sum=0;
    while (pq.size()){
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
