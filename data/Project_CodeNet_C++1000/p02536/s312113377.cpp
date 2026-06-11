#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define int long long 
#define test int qt;cin>>qt;while (qt--)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
 
int mod = 1e9 + 7;
vector<int>adj[100005];
vector<bool>vis(100000,false);
void dfs(int node) {
	vis[node] = true;
	for(auto i : adj[node]) {
		if(!vis[i])
			dfs(i);
	}
}
int32_t main()
{
    IOS;
	int n,m;cin>>n>>m;
	FOR(m){
		int x,y;cin>>x>>y;
		x--;y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int count = 0;
	FOR(n){
		if(!vis[i]){
			dfs(i);
			count++;
		}
	}
	cout<<count-1;
    return 0;
}