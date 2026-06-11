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

vector <int> g[200005];
int res[200005];
bool vis[200005];

void dfs(int root,int add){ 
	vis[root]=true;
	for (auto &it: g[root]){ 
		if (!vis[it]){ 
			res[it] += add; 
			dfs(it,res[it]); 
		} 
	} 
} 

signed main()
{
    int n,q; cin>>n>>q; 
    for (int i=1;i<n;i++){
    	int a,b;cin>>a>>b;
    	g[a].pb(b);
    	g[b].pb(a);
    }
    while (q--){
    	int root,add;
    	cin>>root>>add;
    	res[root] += add;
    }
    dfs(1,res[1]);
    for (int i=1;i<=n;i++) cout << res[i]<< " ";
    cout << endl;
    return 0;
}
