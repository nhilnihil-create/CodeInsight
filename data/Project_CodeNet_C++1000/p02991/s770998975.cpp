#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <functional>
//#include <boost/multiprecision/cpp_int.hpp>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)
#define llrep(i, n) for(ll i = 0; i < n; ++i)
#define llREP(i, m, n) for(ll i = m; i < n; ++i)
#define llrrep(i,n) for(ll i = n; i >= 0; --i)
#define llRREP(i, m, n) for(ll i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using pil = std::pair<int, long long>;
using pli = std::pair<long long, int>;
using plpii = std::pair<long long, std::pair<int, int>>;
using pdd = std::pair<double, double>;
using pis = std::pair<int, std::string>;

const long long INF = 1000000000000000001;
const long long _MOD = 1000000007;
const long long MOD = 998244353;
const int ALPHABET = 27;
const double pi = 3.14159265358979;

using namespace std;
//namespace mp = boost::multiprecision;

struct node {
	ll distance[3];
	bool seen[3];
	vector<pil> conected;
};

void dikstra(node* nodes, int startAt) {
	priority_queue<pli, vector<pli>, greater<pli>> que;
	que.push(pli(0, startAt));

	while (!que.empty()) {
		pli t = que.top();
		que.pop();
		if (t.first > nodes[t.second].distance[t.first % 3]) continue;

		rep(i, nodes[t.second].conected.size()) {
			ll minDis = INF;

			rep(j, 3) {
				if (!nodes[t.second].seen[j]) {
					if (nodes[nodes[t.second].conected[i].first].distance[(j + 1) % 3] > nodes[t.second].distance[j] + 1) {
						nodes[nodes[t.second].conected[i].first].distance[(j + 1) % 3] = nodes[t.second].distance[j] + 1;

						minDis = min(minDis, nodes[nodes[t.second].conected[i].first].distance[(j + 1) % 3]);
					}
				}
			}

			if (minDis != INF) {
				que.push(pli(minDis, nodes[t.second].conected[i].first));
			}
		}

		nodes[t.second].seen[t.first % 3] = true;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	pii* uv = new pii[m];
	rep(i, m) cin >> uv[i].first >> uv[i].second;

	node* nodes = new node[n];
	rep(i, n) {
		rep(j, 3) {
			nodes[i].distance[j] = INF;
			nodes[i].seen[j] = false;
		}
	}

	rep(i, m) {
		nodes[uv[i].first - 1].conected.push_back(pil(uv[i].second - 1, 1));
	}

	int s, t;
	cin >> s >> t;
	nodes[s - 1].distance[0] = 0;
	dikstra(nodes, s - 1);

	if (nodes[t - 1].distance[0] != INF) {
		cout << nodes[t - 1].distance[0] / 3 << "\n";
	}
	else {
		cout << "-1" << "\n";
	}

	return 0;
}
