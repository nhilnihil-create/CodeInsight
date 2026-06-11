void solve();

int main() {
	solve();
	return 0;
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

int N, Q;
vector<vector<int>> Edges;
vector<int> in;
vector<int> sum;
vector<bool> check;
queue<pair<int, int>> que;

void solve() {
	cin >> N >> Q;
	Edges.resize(N);
	for (int n = 1; n <= N - 1; n++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		Edges[a].push_back(b);
		Edges[b].push_back(a);
	}
	in.resize(N,0);
	for (int q = 0; q < Q; q++) {
		int p, x;
		cin >> p >> x;
		p--;
		in[p] += x;
	}
	sum.resize(N,0);
	check.resize(N, false);
	que.push(pair<int, int>(0, 0));
	while (!que.empty()) {
		int cur = que.front().first;
		int s = que.front().second;
		que.pop();
		sum[cur] += (s+in[cur]);
		check[cur] = true;
		for (auto itr = Edges[cur].begin(); itr != Edges[cur].end(); itr++) {
			if (check[*itr])continue;
			que.push(pair<int, int>(*itr, sum[cur]));
		}
	}
	for (int n = 0; n < N; n++)cout << sum[n] << " ";
	return;
}
