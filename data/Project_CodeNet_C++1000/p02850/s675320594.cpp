#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
vector<int> g[N];
int a[N], b[N], c[N];

void dfs(int v, int p, int col){
	int cind = 1;
	for(auto ind : g[v]){
		if(cind == col)cind++;
		int u = a[ind]^b[ind]^v;
		if(u != p){
			c[ind] = cind;
			dfs(u, v, cind);
			cind++;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	for(int i = 1; i < n; i++){
		cin>>a[i]>>b[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}
	int v = 1;
	for(int i = 2; i <= n; i++){
		if(g[i].size() > g[v].size())v = i;
	}
	dfs(v, -1, 0);
	int k = g[v].size();
	cout<<k<<'\n';
	for(int i = 1; i < n; i++){
		cout<<c[i]<<'\n';
	}

	return 0;
}