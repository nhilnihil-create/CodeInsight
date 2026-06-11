#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using str = string;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
const double PI = 3.141592653589793238;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define REP(i, m, n) for (int i = m; i < (int)n; i++)
#define all(a) (a).begin(), (a).end()
#define allg(a) (a).begin(), (a).end(), greator<>()
#define d20 std::setprecision(20)
#define veci vector<int>
#define vecll vector<long long int>
#define vecb vector<bool>
#define vecd vector<double>
template <typename T>
T lcm(T a, T b)
{
	return a / __gcd(a, b) * b;
}

int main()
{
	ll L, R;
	cin >> L >> R;
	if (R - L + 1 >= 2070)
		cout << 0 << endl;
	else
	{
		int ans = INT_MAX;
		for (ll i = L; i <= R - 1; i++)
			for (ll j = i + 1; j <= R; j++)
				ans = min<ll>(ans, (i * j) % 2019);
		cout << ans << endl;
	}

	return 0;
}