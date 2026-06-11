#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; ++i)
using namespace std;
using ll = long long;

int divceil(int a, int b) {
	return (a + b - 1) / b;
}

int main() {
	int k, q;
	cin >> k >> q;
	vector<int> d(k);
	rep(i, k) cin >> d[i];
	rep(qi, q) {
		int n, x, m;
		cin >> n >> x >> m;
		ll last = x, eq = 0;
		//diが何回出されるかを計算
		rep(i, k) {
			ll num = divceil(n - 1 - i, k);
			last += (d[i] % m) * num;
			if (d[i] % m == 0) eq += num;
			//ここで最終的な答えが分かります。
		}
		ll ans = n - 1 - (last / m - x / m) - eq;
		cout << ans << endl;
	}
	return 0;
}
