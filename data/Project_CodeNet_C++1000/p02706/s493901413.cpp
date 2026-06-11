#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll unsigned long long

const ll MOD = 1000000000000000000;

int main() {
	//入力
	int n,m;
	cin >> n >> m;
	vector<int> a(m);
	rep(i, m) cin >> a[i];

	//処理
	int k = 0;
	rep(i, m) {
		k += a[i];
	}

	//出力
	int ans = -1;
	if (k <= n)
		ans = n - k;

	cout << ans << endl;

	return 0;
}
