#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, m; cin >> n >> m;
	vector<int> v[100001];
	for (int i=0; i<n; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}

	int ret = 0;
	priority_queue<int> q;
	for (int i=1; i<=m; i++) {
		for (auto p : v[i]) q.push(p);
		if (!q.empty()) {
			ret += q.top();
			q.pop();
		}
	}
	cout << ret << endl;
	return 0;
}
