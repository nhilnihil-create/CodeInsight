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
	int T1, T2;
	cin >> T1 >> T2;
	int A1, A2;
	cin >> A1 >> A2;
	int B1, B2;
	cin >> B1 >> B2;
	int diff1 = A1 - B1;
	int diff2 = A2 - B2;
	int dis1 = T1 * diff1, dis2 = T2 * diff2;
	if(dis1 == -dis2) {
		out("infinity");
		return 0;
	}
	if(abs(dis1) > abs(dis2) || (dis1 > 0 == dis2 > 0)) {
		out(0);
		return 0;
	}
	// 必ずdis1 < dis2!
	int x = -dis1 / (dis2 + dis1);
	if(dis1 % abs(dis2 + dis1)) {
		out(1 + 2 * x);
	} else {
		out(1 + 2 * (x - 1) + 1);
	}
}