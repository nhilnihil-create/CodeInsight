#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = INT_MAX;
constexpr ll L_INF = LLONG_MAX;

//===




int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll T1, T2, A1, A2, B1, B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

	ll d = (A1 * T1 + A2 * T2) - (B1 * T1 + B2 * T2);

	ll ans;

	if (d == 0) {
		cout << "infinity" << endl;
		return 0;
	}
	else if (d > 0) {
		if (A1 - B1 > 0) {
			cout << 0 << endl;
			return 0;
		}

		ans = (d - (A1 * T1 - B1 * T1)) / d * 2 - 1;

		if ((d - (A1 * T1 - B1 * T1)) % d == 0) --ans;
	}
	else {
		if (A1 - B1 < 0) {
			cout << 0 << endl;
			return 0;
		}

		d = -d;
		ans = (d + (A1 * T1 - B1 * T1)) / d * 2 - 1;

		if ((d - (A1 * T1 - B1 * T1)) % d == 0) --ans;
	}

	cout << ans << endl;


	return 0;
}