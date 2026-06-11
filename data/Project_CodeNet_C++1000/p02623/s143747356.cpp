#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
	//入力
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n); rep(i, n)cin >> a[i];
	vector<int> b(m); rep(i, m)cin >> b[i];
	//計算
	ll t = 0;
	rep(i, m) t=t+b[i];
	int j = m; int ans = 0;
	rep(i, n + 1) {
		while (j > 0 && t > k) {
			j = j - 1; t = t - b[j];
		}
		if (t > k) { break; }
		ans = max(ans, i + j);
		if (i == n) { break; }
		t = t + a[i];
	}
	//答えを出力
	cout << ans << endl;
	return 0;
}
