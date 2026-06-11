#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Nmax = 2e5 + 10;
int cnt[Nmax];
vector<int> a[Nmax];

void dfs(int u, int parent) {
	for (auto& v : a[u]) {
		if (v == parent)
			continue;
		dfs(v, u);
		cnt[u]++;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		a[--p].push_back(i);
	}
	dfs(0, -1);
	for (int i = 0; i < n; ++i)
		cout << cnt[i] << "\n";
}