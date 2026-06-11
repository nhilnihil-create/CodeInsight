#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int m;
	cin >> m;
	ll k = 0, s = 0;
	rep(i, m) {
		ll d, c;
		cin >> d >> c;
		k += c;
		s += d * c;
	}
	cout << (k - 1) + (s - 1) / 9 << endl;
	return 0;
}