#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

const int INF = 1 << 30;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 10000;

vector<int> G[MAX];
int T[MAX];
int A[N], B[N];

int find_next(int i, int n) {
	int ret = -1;
	for (int j = i; j < n; j++) {
		if (T[j]) continue;
		ret = j;
		break;
	}
	return ret;
}

int main() {
	int n, m; cin >> n >> m;
	rep(i, m) {
		int s, t; cin >> s >> t;
		G[s].push_back(t);
		G[t].push_back(s);
		T[i] = 0;
	}
	int q; cin >> q;
	rep(i, q) {
		int a, b; cin >> a >> b;
		A[i] = a; B[i] = b;
	}

	queue<int> Q;
	int next = 0, type = 0;
	while (true) {
		if (Q.empty()) {
			int i = find_next(next, n);
			if (i == -1) break;
			type++;
			T[i] = type;
			Q.push(i);
			continue;
		}
		int i = Q.front(); Q.pop();
		for (auto j : G[i]) {
			if (T[j]) continue;
			T[j] = type;
			Q.push(j);
		}
	}
	rep(i, q) {
		if (T[A[i]] == T[B[i]]) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}

