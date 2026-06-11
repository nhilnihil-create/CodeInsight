#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main() {
	int m; cin >> m;
	ll hoge = 0LL;
	while (m--) {
		int d; ll c;
		cin >> d >> c;
		hoge += d * c;
		hoge += c * 9;
	}
	cout << ((hoge - 18) / 9 + (hoge % 9 == 0 ? 0 : 1)) << endl;
	return 0;
}