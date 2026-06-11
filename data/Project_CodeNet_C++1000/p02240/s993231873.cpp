#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> GetAdjacencyList(int n, int m)
{
	vector<vector<int>> al(n);
	for (int i = 0; i < m; i++) {
		int s, t;
		cin >> s >> t;
		al[s].push_back(t);
		al[t].push_back(s);
	}
	return al;
}

void BFS(int i, const vector<vector<int>>& al, vector<int>& group)
{
	queue<int> q;
	q.push(i);
	group[i] = i + 1;
	while (!q.empty()) {
		int node = q.front(); q.pop();
		for (const auto& item : al[node]) {
			if (group[item]) continue;
			q.push(item);
			group[item] = i + 1;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> al = GetAdjacencyList(n, m);
	vector<int> group(n);
	for (int i = 0; i < n; i++) {
		if (!group[i]) BFS(i, al, group);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int s, t;
		cin >> s >> t;
		if (group[s] == group[t]) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}

