// #define _GLIBCXX_DEBUG
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using vvi = vector<vi>; using vl = vector<ll>; using vvl = vector<vl>; using vb = vector<bool>; using vvb = vector<vb>;
#define rep0(TMS) for (int CNT = 0; CNT < (int)(TMS); CNT++)
#define rep(CNT, GOAL) for (int CNT = 0; CNT < (int)(GOAL); CNT++)
#define rep2(CNT, START, GOAL) for (int CNT = (int)(START); CNT < (int)(GOAL); CNT++)
#define rep3(CNT, START, GOAL) for (int CNT = (int)(START); CNT > (int)(GOAL); CNT--)
#define all(CONT) begin(CONT), end(CONT)
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
void prec(const int &DIG) { cout << fixed << setprecision(DIG); cerr << fixed << setprecision(DIG); }
template <typename T> void CERR(const T &ELEM) { cerr << ELEM; }
#define dbl(OBJ) cerr << #OBJ << ": "; CERR(OBJ); cerr << "\n"
template <typename T, typename ...Ts> void CERR(const T &FIRST, const Ts &...REST) { CERR(FIRST); cerr << ", "; CERR(REST...); }
#define dbs(...) cerr << "(" << #__VA_ARGS__ << "): ("; CERR(__VA_ARGS__); cerr << ")\n"
#define itrep(ITR, CONT) for (auto ITR = begin(CONT); ITR != end(CONT); ITR++)
template <typename T> void CERR(const vector<T> &VEC) { cerr << "{ "; itrep(ITR, VEC) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
#define YN(FLG) cout << (FLG ? "YES" : "NO") << "\n"
#define Yn(FLG) cout << (FLG ? "Yes" : "No") << "\n"
#define yn(FLG) cout << (FLG ? "yes" : "no") << "\n"
// const ll INF = LONG_LONG_MAX;
const int INF = INT_MAX;
// const ll MOD = 1000000007; // 998244353;

// #include <atcoder/all>
// using namespace atcoder;

// iの倍数は1~Nに[N/i]個ある->合計を求められる
// i=1~Nについて上記を加算する

int main() {
	int N; cin >> N;
	ll ans = 0;
	rep2(i, 1, N + 1) {
		ll m = N / i; // iの倍数の個数
		ll temp = (i + m * i) * m / 2;
		ans += temp;
	}
	cout << ans << endl;
}