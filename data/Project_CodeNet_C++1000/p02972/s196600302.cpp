#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> P;
#define INF 10000000000000
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
#define repN_1(i, n) for(ll i = 0; i < (ll)(n - 1); i++)
#define repM(i, n) for(ll i = (ll)(n - 1); i >= 0; i--)
#define repM1(i, n) for(ll i = (ll)(n - 1); i > 0; i--)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main()
{
	cout << fixed << setprecision(18);

	ll n, m;
	cin >> n;
	m = 0;

	vector<ll> a(n + 1), b(n + 1, 0);

	rep1(i, n +1)
		cin >> a[i];

	ll count = 0;

	repM1(i, n + 1) {
		ll j = 2;
		ll c = 0;
		while (i * j <= n) {
			c += b[i * j];
			j++;
		}

		if (c % 2 != a[i]) {
			b[i] = 1;
			count++;
		}
	}

	cout << count << endl;
	rep1(i, n + 1) {
		if (b[i] == 1)
			cout << i << " ";
	}
	cout << endl;

	return 0;
}