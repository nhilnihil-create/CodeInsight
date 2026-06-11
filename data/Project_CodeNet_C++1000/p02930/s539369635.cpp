#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }

template<typename T>
vector<T> gen_v(size_t a) { return vector<T>(a); }
template<typename T, typename ...Ts>
auto gen_v(size_t a, Ts... ts) { return vector<decltype(gen_v<T>(ts...))>(a, gen_v<T>(ts...)); }
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T & t, const V & v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T & t, const V & v) { for (auto& e : t) fill_v(e, v); }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<vector<int>> v(N, vector<int>(N));

	vector<int> d(N + 1, -1);

	int id = 0;
	rep(k, 1, N + 1) {
		if (d[k] == -1) {
			for (int i = k; i < N + 1; i += 2 * k) {
				d[i] = id;
			}
			id++;
		}
	}
	dump(d);

	rep(i, 0, N) {
		rep(j, i + 1, N) {
			v[i][j] = d[j - i];
		}
	}

	rep(i, 0, N) {
		rep(j, i + 1, N) {
			if (j != i + 1)cout << " ";
			cout << v[i][j] + 1;
		}
		cout << endl;
	}

	return 0;
}