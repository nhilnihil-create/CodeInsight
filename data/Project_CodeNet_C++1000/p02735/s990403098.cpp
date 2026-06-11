#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;

using PII = pair<int, pair<int, int>>;
int main() {
	int n, m;
	cin >> n >> m;
	string A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<vector<int>> dist(n, vector<int>(m, MOD));
	dist[0][0] = (A[0][0] == '#');
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({dist[0][0], {0, 0}});
	while(!pq.empty()) {
		int x = pq.top().ss.ff;
		int y = pq.top().ss.ss;
		pq.pop();
		if (x+1 < n) {
			if (dist[x+1][y] > dist[x][y] + ((A[x+1][y] == '#') && (A[x][y] != A[x+1][y]))) {
				dist[x+1][y] = dist[x][y] + ((A[x+1][y] == '#') && (A[x][y] != A[x+1][y]));
				pq.push({dist[x+1][y], {x+1, y}});
			}
		}
		if (y+1 < m) {
			if (dist[x][y+1] > dist[x][y] + ((A[x][y+1] == '#') && (A[x][y] != A[x][y+1]))) {
				dist[x][y+1] = dist[x][y] + ((A[x][y+1] == '#') && (A[x][y] != A[x][y+1]));
				pq.push({dist[x][y+1], {x, y+1}});
			}
		}
	}
	cout << dist[n-1][m-1];
}
