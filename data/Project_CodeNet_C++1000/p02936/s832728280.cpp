#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

vector<vector<int>> E;
vector<int> P, A;

void DFS(int cur, int p, int t) {
	for (int i = 0; i < E[cur].size(); i++) {
		int n = E[cur][i];
		if (n == p) continue;
		A[n] += t + P[n];
		DFS(n, cur, t + P[n]);
	}
	return;
}

int main() {
	int N, Q;
	cin >> N >> Q;

	E.assign(N, vector<int>());
	P.resize(N);
	A.assign(N, 0);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	for (int i = 0; i < Q; i++) {
		int p, x;
		cin >> p >> x;
		p--;
		P[p] += x;
	}

	A[0] += P[0];
	DFS(0, -1, P[0]);

	for (int i = 0; i < N; i++) {
		if (i) cout << ' ';
		cout << A[i];
	}
	cout << endl;
}