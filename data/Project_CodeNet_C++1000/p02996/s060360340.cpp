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

	int n;
	cin >> n;
	vector<Pll> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i].second >> w[i].first;
	}
	sort(w.begin(), w.end());
	ll now = 0;
	for (int i = 0; i < n; i++) {
		int a = w[i].second;
		int b = w[i].first;

		now += a;
		if (now > b) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}