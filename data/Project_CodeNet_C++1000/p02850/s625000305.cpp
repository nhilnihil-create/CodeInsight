#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> graph[100000];
vector<tuple<int, int, int>> ans;
bool isReach[100000] = {false};
void dfs(int node, int par, int pColor) {
	if (isReach[node]) {
		return;
	}
	isReach[node] = true;
	// printf("node:%d\n", node);
	int color = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int nn = graph[node][i];
		if (par == nn)
			continue;
		if (color == pColor)
			color++;
		ans.push_back(make_tuple(nn, node, color));
		dfs(nn, node, color);
		color++;
	}
	return;
}
int main() {
	int n;
	scanf("%d", &n);
	int a[100000], b[100000];
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		graph[a[i]].push_back(b[i]);
		graph[b[i]].push_back(a[i]);
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		k = max(k, (int)graph[i].size());
	}
	dfs(0, -1, -1);
	cout << k << endl;
	map<pair<int, int>, int> t;
	for (int i = 0; i < ans.size(); i++) {
		t[pair<int, int>(get<0>(ans[i]), get<1>(ans[i]))] = get<2>(ans[i]);
		t[pair<int, int>(get<1>(ans[i]), get<0>(ans[i]))] = get<2>(ans[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		cout << t[pair<int, int>(a[i], b[i])] << endl;
	}
	return 0;
}