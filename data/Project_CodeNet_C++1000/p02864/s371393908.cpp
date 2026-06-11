#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
vector<int> compress1(int* v, int n, vector<int> def) {
	vector<int> dic(all(def));
	rep(i, 0, n) dic.push_back(v[i]);
	sort(all(dic));
	dic.erase(unique(all(dic)), dic.end());
	rep(i, 0, n) v[i] = lower_bound(all(dic), v[i]) - dic.begin();
	return dic;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/








int N, K, H[301];
ll dp[301][301][301];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> H[i];

	auto dic = compress1(H, N, { 0 });
	int M = dic.size();

	rep(i, 0, N + 1) rep(k, 0, K + 1) rep(h, 0, M) dp[i][k][h] = infl;
	dp[0][0][0] = 0;

	rep(i, 0, N) {
		rep(k, 0, K) rep(h, 1, M) chmin(dp[i + 1][k + 1][h], min(dp[i][k][h - 1], dp[i + 1][k + 1][h - 1]) + dic[h] - dic[h - 1]);
		rep(k, 0, K) {
			ll mi = infl;
			rrep(h, M - 1, 0) {
				chmin(mi, dp[i][k][h]);
				chmin(dp[i + 1][k + 1][h], mi);
			}
		}
		rep(k, 0, K + 1) rep(h, 0, M) chmin(dp[i + 1][k][H[i]], dp[i][k][h] + max(0, dic[H[i]] - dic[h]));
	}

	ll ans = infl;
	rep(k, 0, K + 1) rep(h, 0, M) chmin(ans, dp[N][k][h]);
	cout << ans << endl;
}





