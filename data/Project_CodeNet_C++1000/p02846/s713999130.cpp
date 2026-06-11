#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	ll T1, T2, A1, A2, B1, B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

	ll AB1 = A1 - B1;
	ll AB2 = A2 - B2;
	AB1 *= T1;
	AB2 *= T2;

	if (AB1 == 0 || AB2 == 0) {
		co(0);
	}
	else {
		if (AB1 > 0 && AB2 > 0) co(0);
		else if (AB1 < 0 && AB2 < 0) co(0);
		else {
			if (AB1 + AB2 == 0) co("infinity");
			else {
				if (AB1 < 0) {
					AB1 = -AB1;
					AB2 = -AB2;
				}
				ll tmp = AB1 + AB2;
				if (tmp > 0) co(0);
				else {
					tmp = -tmp;
					if (AB1 % tmp == 0) {
						co(AB1 / tmp * 2);
					}
					else {
						co(AB1 / tmp * 2 + 1);
					}
				}
			}
		}
	}



	Would you please return 0;
}