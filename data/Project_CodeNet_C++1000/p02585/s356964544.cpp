#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <cmath>
#include <stdlib.h> 
#include <stdio.h>
#include <iterator>
#include <chrono>
#include <iomanip>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include <deque>
#include <stack>
#include <queue>
#include <fstream>
#include <limits>
#include <unordered_map>
#include <bitset>
#include <numeric>
#include <sstream>
#include <random>
#include <cassert>

using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;

long long total, maximum, len, total_maximum;

void dfs(int node, vector <int> & visited, vector <int>& next, vector <int>& cost) {
	if (visited[node] == 1) return;
	len++;
	visited[node] = 1;
	total += cost[node];
	dfs(next[node], visited, next, cost);
}

long long dfs3(int node, vector <int>& next, vector <int>& cost, int steps) {
	if (steps <= 0) return 0;
	return max((long long)0, cost[node] + dfs3(next[node], next, cost, steps - 1));
}

void dfs2(int node, vector <int>& visited, vector <int>& next, vector <int>& cost, int steps) {
	if (visited[node] == 2) return;
	visited[node] = 2;
	maximum = max(maximum, dfs3(node, next, cost, steps));
	total_maximum = max(total_maximum, dfs3(node, next, cost, len));
	dfs2(next[node], visited, next, cost, steps);
}


int main(void) {
	cin.tie(0); ios::sync_with_stdio(0);

	long long ans = -INF;
	long long n, k, x;
	cin >> n >> k;
	vector <int> next(n), cost(n); vector <int> visited(n);
	ffor(n) {
		cin >> x;
		next[i] = x - 1;
	}
	ffor(n) cin >> cost[i];
	for (auto e : cost) ans = max(ans, (long long)e);

	ffor(n) {
		if (visited[i]) continue;
		total = 0, maximum = 0, len = 0, total_maximum = 0;
		dfs(i, visited, next, cost);
		dfs2(i, visited, next, cost, k % len);
		if (total_maximum == 0) {
			maximum = -INF;
			total_maximum = -INF;
		}
		ans = max({ ans, maximum, maximum + (k / len) * total });
		if (k >= len) ans = max({ ans, total_maximum, ((k / len) - 1) * total + total_maximum });
	}
	cout << ans;
}





/*
C:\Users\User\Desktop\comp_programming\final_straw_after_this_im_switching_to_vs_code\final_straw_after_this_im_switching_to_vs_code.cpp
*/