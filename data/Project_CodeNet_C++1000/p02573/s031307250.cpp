#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define maxN 200015

int n, m, cnt;
vector<int> visited(maxN, 0);
vector<int> adj[maxN];

//vector<int> adj[maxN];

void dfs(int s) {
	visited[s] = 1;
	cnt++;
	for (auto i : adj[s]) {
		if (visited[i] == 0) {
			dfs(i);
		}
	}

}



int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			cnt = 0;
			dfs(i);
			ans = max(ans, cnt);
		}
	}
	cout << ans << endl;


	return 0;
}