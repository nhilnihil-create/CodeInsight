#include "bits/stdc++.h"
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define RREP(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define RFOR(i, s, n) for (int i = (int)n - 1; i >= s; --i)
#define ALL(a) a.begin(), a.end()
#define IN(a, x, b) (a <= x && x < b)
template<class T>inline void out(T t){cout << t << "\n";}
template<class T,class... Ts>inline void out(T t,Ts... ts){cout << t << " ";out(ts...);}
template<class T>inline bool CHMIN(T&a,T b){if(a > b){a = b;return true;}return false;}
template<class T>inline bool CHMAX(T&a,T b){if(a < b){a = b;return true;}return false;}
constexpr int INF = 1e18;



signed main(){
	int K, Q;
	cin >> K >> Q;
	vector<int>d(K);
	REP(i, K) {
		cin >> d[i];
	}
	vector<int>ans;
	while(Q--) {
		int N, X, M;
		cin >> N >> X >> M;
		N--;
		vector<int>a(K);
		REP(i, K) {
			if(d[i] % M == 0) a[i] = M;
			else a[i] = d[i] % M;
		}
		int as = 0;
		REP(i, K) {
			as += a[i];
		}
		int amari = 0;
		REP(i, N % K) {
			amari += a[i];
		}
		int sum = as * (N / K) + amari + X % M;
		int mod = sum / M;
		ans.emplace_back(N - mod);
	}
	REP(i, ans.size()) {
		out(ans[i]);
	}
}