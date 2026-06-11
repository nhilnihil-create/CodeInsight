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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int mx = (n - 1) * (n - 2) / 2;
	if (k > mx) {
		cout << -1 << endl;
		return 0;
	}

	int add = mx - k;
	vector<P> ans;
	for (int i = 1; i <= n - 1; i++) {
		ans.push_back(P(i, n));
	}
	vector<P> edge;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			edge.push_back(P(i, j));
		}
	}
	for (int i = 0; i < add; i++) {
		ans.push_back(edge[i]);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}

}