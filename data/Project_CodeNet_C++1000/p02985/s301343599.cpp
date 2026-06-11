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

long long int n, k;
vector<vector<int>> graph;
vector<int> parent;

void setparent(int now) {
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (next == parent[now]) continue;
		parent[next] = now;
		setparent(next);
	}
}

long long int solve(int now) {
	long long int restk = k - 2;
	if (parent[now] == -1) restk = k - 1;
	long long int res = 1;
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (next == parent[now]) continue;
		res *= (max((long long int)0, restk) * solve(next)) % mod;
		res %= mod;
		restk--;
	}
	// cout << now << " " << res << endl;
	return res;
}

int main() {
	cin >> n >> k;
	graph = vector<vector<int>>(n);
	parent = vector<int>(n, -1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	setparent(0);
	cout << (k * solve(0)) % mod << endl;
}