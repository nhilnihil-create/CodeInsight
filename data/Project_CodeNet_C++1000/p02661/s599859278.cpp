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

	ll n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n)
		cin >> a[i] >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll ans;
	if (n % 2 == 1) {
		ans = b[(n + 1) / 2 - 1] - a[(n + 1) / 2 - 1] + 1;
	}
	else {
		double tmp_a = (a[n / 2 - 1] + a[(n / 2 + 1) - 1]) * 0.5;
		double tmp_b = (b[n / 2 - 1] + b[(n / 2 + 1) - 1]) * 0.5;

		ll aa = tmp_a * 10 + 0.5;
		ll bb = tmp_b * 10 + 0.5;

		ans = (bb - aa) / 5 + 1;
	}

	cout << ans << endl;

	return 0;
}