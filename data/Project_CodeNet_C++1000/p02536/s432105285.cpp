#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e9 + 5;
#define INF 1000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

std::vector<int> adj[100005];
std::vector<bool> vis(100005,false);

void dfs(int i){
	if(!vis[i]){
		vis[i]=true;
		for(auto v:adj[i]){
			dfs(v);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	int n,m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int suma = 0;
	for(int i=0; i<n; i++){
		if(!vis[i]){
			suma++;
			dfs(i);
		}
	}
	cout << suma-1 << "\n";
    return 0;
}
