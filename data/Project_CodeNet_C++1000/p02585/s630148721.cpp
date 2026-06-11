#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N, K, G[5000], C[5000];
vector < int > costs, vis;

void dfs(int u){
	vis[u] = true;
	costs.push_back(C[u]);
	if (!vis[G[u]])
		dfs(G[u]);
	else
		return;
}

int main(){
	cin >> N >> K;
	for (int i = 0; i < N; i ++){
		int X; cin >> X; X -= 1;
		G[i] = X;
	}
	for (int i = 0; i < N; i ++)
		cin >> C[i];
	long long result = -2e18;
	for (int i = 0; i < N; i ++){
		vis = vector < int > (N, 0);
		costs.clear();
		dfs(G[i]);
		int sz = costs.size();
		int p0 = K / sz, p1 = K % sz;
		long long curr1 = 0;
		for (int i = 0; i < costs.size() && i < K; i ++){
			curr1 += costs[i];
			result = max(curr1, result);
		}
		if (p0 > 0){
			long long curr2 = accumulate(costs.begin(), costs.end(), 0ll) * (p0);
			for (int i = 0; i < costs.size() && i < p1; i ++){
				curr2 += costs[i];
				result = max(curr2, result);
			}
		}
		if (p0 > 1){
			long long curr3 = accumulate(costs.begin(), costs.end(), 0ll) * (p0 - 1);
			for (int i = 0; i < costs.size() && i < K; i ++){
				curr3 += costs[i];
				result = max(curr3, result);
			}
		}
	}
	cout << result << "\n";
}
