#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 999999999;
void solve() {
	int N; cin >> N;
	vector<int64> A(N + 1), S(N + 2);
	for (int i = 0; i <= N; ++i) {
		cin >> A[i];
		S[i + 1] = A[i] + S[i];
	}
	//頂点数は1からスタート
	int64 ans = 0, now = 1;
	for (int i = 0; i <= N; ++i) {
		//現在の頂点数は加算
		ans += now;
		//葉ではない頂点数が葉である頂点数より小さくなると、葉が存在できなくなるので-1を出力する
		if (now < A[i]) {
			cout << -1 << endl;
			return;
		}
		//現在の頂点数から葉である頂点数を引く
		now -= A[i];
		//次の階層に降りた際の葉である頂点数の残数を求める
		int64 s = S[N + 1] - S[i + 1];
		//現在の頂点数 * 2と葉である頂点数の残数のminを次の階層の頂点数とする
		//葉である頂点数の方が小さくなる場合は葉の残数分を頂点を置き、直接連結
		//そうでない場合は葉ではない頂点 * 2個の頂点を置いて、処理を継続
		now = min(now * 2, s);
	}
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}