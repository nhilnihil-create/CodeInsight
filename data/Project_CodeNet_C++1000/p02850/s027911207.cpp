#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

struct edge {
	int to, n;
};
vector<edge> G[100010];
int color[100010];
void dfs(int v, int parent, int c) {
	int cnt = 0;
	for (int i = 0; i < G[v].size(); i++) {
		if (G[v][i].to == parent) continue;
		cnt++;
		if (cnt == c) cnt++;
		color[G[v][i].n] = cnt;
		dfs(G[v][i].to, v, cnt);
	}
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back({ b,i });
		G[b].push_back({ a,i });
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, (int)G[i].size());
	}
	dfs(0, -1, -1);
	cout << ans << endl;
	for (int i = 0; i < N - 1; i++) {
		cout << color[i]<< endl;
	}
}
