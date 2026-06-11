#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long 
#define endl "\n"
#define all(x) (x).begin(),(x).end()
const int MOD = 1e9+7;
const int mxN = 2e5+3;

int parent[mxN];

int find_set(int u){
	if(parent[u] == u)return u;
	return parent[u] = find_set(parent[u]);
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)parent[i] = i;
	int a, b;
	for(int i = 0; i < m; ++i){
		cin >> a >> b;
		a = find_set(a);
		b = find_set(b);
		if(a != b){
			if(a < b)parent[b] = a;
			else parent[a] = b;
		}
	}
	map<int, int> mp;
	for(int i = 1; i <= n; ++i){
		mp[find_set(i)]++;
	}
	int mx = 0;
	for(auto it : mp){
		mx = max(mx, it.second);
	}
	cout << mx << endl;
}

int32_t main(){
	IO;
	
	int nT = 1;
	//cin >> nT;
	for(int i = 1; i <= nT; ++i)
		solve();
	return 0;
}
