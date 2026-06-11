#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<queue>
#include<iomanip>
#include<bitset>
#include<math.h>
#include<stack>
#include<set>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int n, x, y;
	cin >> n >> x >> y;
	x--; y--;
	queue<int> q;
	vector<bool> used(n, 0);
	vector<int> t1(n);
	vector<int> t2(n);
	used[x] = 1;
	q.push(x);
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		vector<int> g;
		g.push_back(a - 1);
		g.push_back(a + 1);
		if (a == x) {
			g.push_back(y);
		}
		if (a == y) {
			g.push_back(x);
		}
		for (int i = 0; i < g.size(); i++) {
			int to = g[i];
			if (to >= 0 && to < n) {
				if (!used[to]) {
					used[to] = 1;
					q.push(to);
					t1[to] = t1[a] + 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		used[i] = 0;
	}
	used[y] = 1;
	q.push(y);
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		vector<int> g;
		g.push_back(a - 1);
		g.push_back(a + 1);
		if (a == x) {
			g.push_back(y);
		}
		if (a == y) {
			g.push_back(x);
		}
		for (int i = 0; i < g.size(); i++) {
			int to = g[i];
			if (to >= 0 && to < n) {
				if (!used[to]) {
					used[to] = 1;
					q.push(to);
					t2[to] = t2[a] + 1;
				}
			}
		}
	}
	vector<int> r(n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			r[min(j - i, min(t1[i] + t1[j], t2[i] + t2[j]))]++;
		}
	}
	for (int i = 1; i < n; i++) {
		cout << r[i] << endl;
	}
}
	