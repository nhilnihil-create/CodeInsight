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
const int MOD = 998244353;
const ll INF = 1000000000000000000;

vector<int> G[200010];
int d[200010];
void dfs(int v, int parent) {
	for (int to : G[v]) {
		if (to == parent) continue;
		d[to] += d[v];
		dfs(to, v);
	}
}
int main()
{
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	while (Q--) {
		int p, x;
		cin >> p >> x;
		p--;
		d[p] += x;
	}
	dfs(0, -1);
	for (int i = 0; i < N; i++) {
		if (i != 0) cout << " ";
		cout << d[i];
	}
	cout << endl;
}