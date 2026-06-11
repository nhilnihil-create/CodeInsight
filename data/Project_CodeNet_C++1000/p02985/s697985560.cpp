#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long M = 1000000007;

int N, K;
vector<int> v[100005];
int a[100005];

void dfs(int x, int p, bool islyr1) {
	int cur = K-2;
	if (islyr1) cur++;
	for (auto it:v[x]) {
		if (it==p) continue;
		a[it] = cur--;
		dfs(it, x, 0);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	a[1] = K;
	dfs(1, -1, 1);
	long long ans = 1;
	for (int i = 1; i <= N; i++) {
		ans *= a[i];
		ans %= M;
	}
	cout << ans;
}
