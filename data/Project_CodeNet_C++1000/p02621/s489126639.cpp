//const int N=1e5;
#define INF 1e9
#include <bits/stdc++.h>
using namespace std;
const int M = 100;

void sol() {
	int n; cin >> n;
	cout << (n + (n * n) + (n * n * n));
}

int main() {
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		sol();
	}

	return 0;
}