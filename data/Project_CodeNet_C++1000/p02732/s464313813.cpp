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
const int MAX = 500000;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}

long long COM(int n, int k)
{
	if (n < k)
		return 0;
	if (n < 0 || k < 0)
		return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main()
{
	int n;
	cin >> n;
	map<ll, ll> _map;
	vecll a(n);
	rep(i, n)
	{
		cin >> a[i];
		_map[a[i]]++;
	}
	ll sum = 0;
	for (auto x : _map)
	{
		sum += x.second * (x.second - 1) / 2;
	}
	for (auto i = 0; i < n; i++)
	{
		cout << sum - _map[a[i]] + 1 << endl;
	}
	return 0;
}