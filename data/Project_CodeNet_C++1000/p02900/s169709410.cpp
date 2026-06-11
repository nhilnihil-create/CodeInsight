#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
map<int, int> mp;
void prime_factorize(ll n, vector<ll> &ret)
{
	if (n <= 1)	return;
	ll last = sqrt(n);
	for (ll i = 2; i <= last; i++) {
		if (n % i == 0) {
			prime_factorize(i, ret);
			prime_factorize(n / i, ret);
			return;
		}
	}
	ret.push_back(n);
	return;
}
int getDig(ll i)
{
	int dig = 0;
	while (i != 0) {
		i /= ll(10);
		dig++;
	}
	return dig;
}
ll getGCD(ll a, ll b)
{
	// Greatest Common Divisor
	if (a == b)	return a;
	ll _min = min(a, b);
	ll _max = max(a, b);
	if (_max % _min == 0)	return _min;
	return getGCD(_min, _max%_min);
}
ll getLCM(ll a, ll b)
{
	// Least Common Multiple
	return a*b / getGCD(a, b);
}
vector<ll> divisor(ll n)
{
	vector<ll> ret;
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n)	ret.push_back(n / i);
		}
	}
	return ret;
}
int main()
{
	ll a, b;
	cin >> a >> b;
	ll gcd = getGCD(a, b);
	vector<ll> fac = divisor(gcd);
	sort(fac.begin(), fac.end());
	int s = fac.size();
	vector<ll> disjoints(1, 1);
	if (s == 1) {
		cout << 1 << endl;
		return 0;
	}
	ll ans = 1;
	for (int i = 1; i < s; ++i) {
		bool ok = true;
		rep(j, disjoints.size()) {
			//if (disjoints[j] == fac[i])	continue;
			gcd = getGCD(disjoints[j], fac[i]);
			if (gcd != 1) {
				ok = false;
				break;
			}
		}
		if (ok) {
			disjoints.push_back(fac[i]);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
