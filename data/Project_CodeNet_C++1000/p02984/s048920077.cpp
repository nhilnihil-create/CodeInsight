#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <stack>
#include <deque>
#include <queue>
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
	vector<ll> a(n+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> b(n + 1);
	b[0] = 0;
	for (int i = 0; i < n; i++) {
		b[i + 1] = 2 * a[i] - b[i];
	}
	vector<ll> ans(n);
	ans[0] = (b[0] + b[n]) / 2;
	for (int i = 0; i < n-1; i++) {
		ans[i + 1] = 2 * a[i] - ans[i];
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}