#include<iostream>
#include<cstdlib>
#include<utility>
#include<tuple>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<queue>
#include<deque>
#include<bitset>
#include<cmath>
#include<map>
#include<iomanip>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
#define rep(i, a, b) for(ll i = a; i < b; i++)

int main() {

	int n, m, x;
	cin >> n >> m >> x;

	vector<int> c(n);
	vector<vector<int>> a(n, vector<int>(m));

	rep(i, 0, n) {
		cin >> c[i];
		rep(j, 0, m) cin >> a[i][j];
	}

	int ans = 12000001;
	int all = 1 << n; //先頭だけ1の本の数と同じ長さのビット
	rep(mask, 0, all) {
		vector<int> level(m);//理解度
		int cost = 0;//コスト
		rep(i, 0, n) {
			if ((mask >> i) & 1) {//maskのi番目が1だったら
				cost += c[i];
				rep(j, 0, m) {
					level[j] += a[i][j];
				}
			}
		}
		bool ok = true;
		rep(j, 0, m) {
			if (level[j] < x) ok = false;//どれか1個でもx以下なら
		}
		if (ok) ans = min(ans, cost);
	}
	if (ans == 12000001) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}
