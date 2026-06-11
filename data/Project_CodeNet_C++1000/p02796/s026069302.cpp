#pragma region Template
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define rng(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define rbf(i, v) for (auto& (i) : (v))
#define All(x) (x).begin(),(x).end()
#define cAll(x) (x).cbegin(),(x).cend()
#define COL(x) cout << x << endl
#define CO(x) cout << x
//#define int long long

using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VP = vector<PII>;

const double PI = 3.141592653589793;
const int MOD = 1000000007;
const LL INF64 = INT64_MAX >> 1;
const int INF = INT_MAX >> 1;

inline int sqr(int x) { return (x * x); }
inline void printd(double x) { printf("%.10lf\n", x); }
inline void upsort(VI& x) { sort((x).begin(), (x).end()); }
inline void downsort(VI& x) { sort((x).begin(), (x).end(), greater<int>()); }
inline int absdiff(int a, int b) {
	if (b > a) return absdiff(b, a);
	return (a - b);
}
int gcd(int a, int b) { // 最大公約数
	if (a < b) return gcd(b, a);
	int r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}
inline int lcm(int a, int b) { return a * b / gcd(a, b); } // 最小公倍数
#pragma endregion



signed main()
{	
	int N;
	cin >> N;

	VI X(N), L(N);
	rep(i, N) {
		cin >> X[i] >> L[i];
	}

	VP arm(N);
	rep(i, N) {
		// pairは辞書順で比較される
		// 終端が小さい順にしたいため、終端をfirstにする
		arm[i].first = X[i] + L[i];  // アームの終端
		arm[i].second = X[i] - L[i]; // アームの始端
	}

	// アームの終端が小さい順に残すロボットを決めることで最大化できる
	sort(All(arm));
	int ans = 0, pre = -INF;
	rbf(a, arm) {
		if (a.second >= pre) {
			ans++;
			pre = a.first;
		}
	}

	COL(ans);
	return 0;
}