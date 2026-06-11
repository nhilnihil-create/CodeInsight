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
    int x,y,r,g,c; 
    cin>>x>>y>>r>>g>>c; 
    int R[r],G[g],C[c];
    for (int i=0;i<r;i++) cin>>R[i];
    for (int i=0;i<g;i++) cin>>G[i];
    for (int i=0;i<c;i++) cin>>C[i];
    sort(R, R+r, greater<int> ()); 
    sort(G, G+g, greater<int> ()); 
    sort(C, C+c, greater<int> ()); 
    priority_queue<int> pq;
    for (int i=0;i<min(r,x);i++) pq.push(R[i]);
    for (int i=0;i<min(g,y);i++) pq.push(G[i]);
    for (int i=0;i<min(c,x+y);i++) pq.push(C[i]);
    int sum=0,i=0;
    while (pq.size() && i<(x+y)){
        sum += pq.top();
        i++; pq.pop(); 
    }
    printf("%lld\n",sum);
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
