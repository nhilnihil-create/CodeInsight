#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <deque>
#include <queue>
#include <map>
#include <iterator>
#include <set>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e) { std::cout << e << std::endl; }
template<typename T> void view(const std::vector<T>& v) { for (const auto& e : v) { std::cout << e << " "; } std::cout << std::endl; }
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v : vv) { view(v); } }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int mxV = 10009;
const int mxE = 100009;
vector<int> G[mxV];
int in[mxV];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int v, e;
	cin >> v >> e;
	fill(in, in + v, 0);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		in[b]++;
	}

	queue<int> Q;
	for (int i = 0; i < v; i++) {
		if (in[i] == 0) {
			Q.push(i);
		}
	}

	vector<int> ans;

	while (!Q.empty()) {
		int p = Q.front();
		Q.pop();

		for (auto e : G[p]) {
			in[e]--;
			if (in[e] == 0) {
				Q.push(e);
			}
		}

		ans.push_back(p);
	}

	for (auto e : ans) {
		cout << e << endl;
	}

}
