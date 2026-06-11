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
using pli = std::pair<long long, int>;
using plpii = std::pair<long long, std::pair<int, int>>;
using pdd = std::pair<double, double>;

using namespace std;

const long long _MOD = 1000000007;
const long long MOD = 998244353;
const int ALPHABET = 27;
const double pi = 3.14159265358979;

struct node {
	vector<int> children;
};

void solve(int nodeNum, int num, node* nodes, ll k, ll &ans) {
	ll t = 2;
	if (nodeNum == 0) t = 1;

	int counter = 0;
	rep(i, nodes[nodeNum].children.size()) {
		if (nodes[nodeNum].children[i] != num) {
			ans *= k - t - counter;
			ans %= _MOD;

			solve(nodes[nodeNum].children[i], nodeNum, nodes, k, ans);

			++counter;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	ll k;
	cin >> n >> k;
	node* nodes = new node[n];
	int a, b;
	rep(i, n - 1) {
		cin >> a >> b;
		nodes[a - 1].children.push_back(b - 1);
		nodes[b - 1].children.push_back(a - 1);
	}

	ll ans = k;
	solve(0, -1, nodes, k, ans);

	cout << ans << "\n";

	return 0;
}

