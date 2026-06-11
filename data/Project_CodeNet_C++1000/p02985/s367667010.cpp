#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>
#include <random>
#include <complex>
#include <functional>
#include <tuple>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")

using ll = long long;

using pint = std::pair<int, int>;
using pll = std::pair<ll, ll>;


constexpr int inf = 1e9 + 7;
constexpr ll infll = 1ll << 60ll;
constexpr ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

namespace {
	template<typename T> void chmax(T& a, T b) { a = std::max(a, b); }
	template<typename T> void chmin(T& a, T b) { a = std::min(a, b); }
	template<typename T> void chadd(T& a, T b) { a = a + b; }

	void Cout(long long x, const char* end = "\n") { std::cout << x << end; }
	template <typename T> void Cout(const T& x, const char* end = "\n") { std::cout << x << end; }
	template <typename T> void Cout(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; i++) { std::cout << x[i] << (i == sz - 1 ? end : sep); } }

	void CCout(long long x, const char* end = "\n") { std::cerr << x << end; }
	template <typename T> void CCout(const T& x, const char* end = "\n") { std::cerr << x << end; }
	template <typename T> void CCout(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; i++) { std::cerr << x[i] << (i == sz - 1 ? end : sep); } }

	// 標準入出力
	struct inp {
		std::size_t sz;
		inp(std::size_t _sz = 1) : sz(_sz) {}
		template <typename T> operator T () const { T a; std::cin >> a; return a; }
		template <typename T> operator std::vector<T>() const { vector<T> a(sz); for (std::size_t i = 0; i < sz; i++) std::cin >> a[i]; return a; }
		template <typename T, typename U> operator std::pair<T, U>() const { T f; U s; std::cin >> f >> s; return std::pair<T, U>(f, s); }
	};

	inp inp1; // input one
}

int main() {

	int n, k;
	cin >> n >> k;
	vector<int> a(n - 1), b(n - 1);
	rep(i, n - 1) cin >> a[i] >> b[i];

	// k色持っている

	// 貪欲で行けそうだな

	vector<vector<int>> g(n, vector<int>());
	rep(i, n - 1) {
		--a[i], --b[i];
		g[a[i]].emplace_back(b[i]);
		g[b[i]].emplace_back(a[i]);
	}

	vector<int> num(n);
	rep(i, n) {
		num[i] = g[i].size();
	}

	vector<bool> used(n, false);

	ll ans = 1;

	// 頂点0から走査する
	queue<pint> que;
	que.push({ 0, 0 });
	used[0] = true;
	{
		pint p = que.front(); que.pop();
		int v = p.first;
		int used_num = p.second;
		// 色を決める
		ans *= k - used_num;
		if (ans < 0) {
			Cout(0);
			return 0;
		}
		ans %= mod;

		int cnt = 0;
		rep(i, g[v].size()) {
			int next = g[v][i];
			if (used[next]) continue;

			++cnt;
			que.push({ next, cnt });
			used[next] = true;
		}
	}

	while (!que.empty()) {
		pint p = que.front(); que.pop();
		int v = p.first;
		int used_num = p.second;
		// 色を決める
		ans *= k - used_num;
		if (ans < 0) {
			ans = 0;
			break;
		}
		ans %= mod;

		int cnt = 1;
		rep(i, g[v].size()) {
			int next = g[v][i];
			if (used[next]) continue;

			++cnt;
			que.push({ next, cnt });
			used[next] = true;
		}
	}

	Cout(ans);


	return 0;
}
