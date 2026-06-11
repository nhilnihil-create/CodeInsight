#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const double PI = 3.1415926535897932384626433832795;
const ll MOD = 1000000007;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : abs(x); }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int n, m, r;

struct edge {
	int from;
	int to;
	int cost;
};

vector<edge> edges;
vector<ll> dist;

bool solve(int start) {
	dist.resize(n, INT_MAX);
	dist[start] = 0;

	int cnt = 1;
	while (true) {
		bool isUpdate = false;
		for (auto e : edges) {
			if (dist[e.from] != INT_MAX && dist[e.to] > dist[e.from] + e.cost) {
				if (cnt == n) {
					return true;
				}

				dist[e.to] = dist[e.from] + e.cost;
				isUpdate = true;
			}
		}

		if (!isUpdate) {
			break;
		}
		cnt++;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 0; i < m; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		edges.push_back({ s, t, d });
	}

	if (solve(r)) {
		cout << "NEGATIVE CYCLE" << endl;
		return 0;
	}

	for (auto v : dist) {
		cout << (v != INT_MAX ? to_string(v) : "INF") << endl;
	}

	return 0;
}

