
// D - Digit Dum Replace

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int M;
	cin >> M;

	ll d, c;
	ll q = 0;
	ll r = -1;
	ll D = 0;
	for (int i=0; i<M; i++) {
		cin >> d >> c;
		q += (d * c + r) / 9;
		r = (d * c + r) % 9;
		D += c;
	}

	ll ans = (D - 1) + q;

	cout << ans << endl;

	return 0;
}