#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>

typedef long double ld;
typedef long long ll;

using namespace std;

#define INF (1 << 20)
#define MAXN (1 << 12)

int d[MAXN];
int v[MAXN];
int n, k;
vector<int> a[MAXN];
int cnt[MAXN];

void bfs(int source) {
	for (int i = 0; i < n; i++) {
		d[i] = INF;
		v[i] = 0;
	}
	queue<int> q;
	q.push(source);
	v[source] = 1;
	d[source] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < a[cur].size(); i++) {
			int t = a[cur][i];
			if (!v[t]) {
				v[t] = 1;
				d[t] = d[cur] + 1;
				q.push(t);
			}
		}
	}
}

void addedge(int x, int y) {
	a[x].push_back(y);
	a[y].push_back(x);
}

int main() {
	int x, y;
	cin >> n >> x >> y;
	for (int i = 0; i < n - 1; i++) {
		addedge(i, i + 1);
	}
	addedge(x - 1, y - 1);

	for (int i = 0; i < n; i++) {
		bfs(i);
		for (int j = 0; j < n; j++) {
			cnt[d[j]]++;
		}
	}
	for (int i = 1; i < n; i++) {
		cout << cnt[i] / 2 << endl;
	}

	return 0;
}
