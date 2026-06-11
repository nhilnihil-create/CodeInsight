#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef pair<ll, ll> P;

#define rep(a,n) for(int a = 0;a < n;a++)
#define repi(a,b,n) for(int a = b;a < n;a++)

const ll mod = 1000000007;

ll t1, t2;
ll a1, a2, b1, b2;

int main(void)
{
	cin >> t1 >> t2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;

	auto c = (a1 - b1) * t1;
	auto d = c + (a2 - b2) * t2;
	if (d == 0) {
		cout << "infinity" << endl;
		return 0;
	}

	auto ac = abs(c);
	auto ad = abs(d);
	if ((c/ac) * (d/ad) > 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << ac / ad * 2 + (ac % ad != 0) << endl;
	return 0;
}
