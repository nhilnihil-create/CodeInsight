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

vector <int> g[2005];
map <int,int> cnt;
bool vis[2005];

signed main()
{
    int n,x,y; 
    cin>>n>>x>>y;
    for (int i=1;i<n;i++) {
        g[i].pb(i+1);
        g[i+1].pb(i);
    }
    g[x].pb(y);
    g[y].pb(x);
    for (int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        queue<int> q;
        q.push(i);
        vi dis(n+1,0);
        vis[i]=true;
        while (q.size()){
            int x=q.front();
            //cout << x << " = "<<dis[x]<<'\n';
            q.pop();
            for (auto &it: g[x]){
                if (!vis[it]) {
                    q.push(it); 
                    vis[it]=true;
                    dis[it]=dis[x]+1;
                    cnt[dis[it]]++;
                }
            }
        }
    }
    for (int i=1;i<n;i++) cout << cnt[i]/2 << endl; 
    return 0;
}
