#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		graph[u].push_back(v);
	}
	int s, t;
	cin >> s >> t;
	s--;
	t--;
	vector<vector<int>> result(n, vector<int>(3, -3));
	result[s][0] = 0;
	queue<pair<int, int>> qu;
	qu.push(make_pair(s, 0));
	while (!qu.empty()) {
		int now = (qu.front()).first;
		int cost = (qu.front()).second;
		qu.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			int nextcost = cost + 1;
			if (result[next][nextcost % 3] >= 0) continue;
			result[next][nextcost % 3] = nextcost;
			qu.push(make_pair(next, nextcost));
		}
	}
	cout << result[t][0] / 3 << endl;
}