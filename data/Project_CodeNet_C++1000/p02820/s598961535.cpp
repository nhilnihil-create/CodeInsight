#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<numeric>
#include<limits>
#include <cstdint>
#include<stack>
#include<queue>
using namespace std;
#define ll long long int
#define rep(N) for(ll i=0;i<N;i++)
#define rep2(N1,N2) for(ll i=0;i<N1;i++)for(ll j=0;j<N2;j++)
#define rep3(N1,N2,N3)for(ll i=0;i<N1;i++)for(ll j=0;j<N2;j++)for(ll k=0;k<N3;k++)
#define For(i,N) for(ll i=0;i<N;i++)

void yn(bool b) {
	if (b)printf("yes\n");
	else printf("no\n");
}

void Yn(bool b) {
	if (b)printf("Yes\n");
	else printf("No\n");
}

void YN(bool b) {
	if (b)printf("YES\n");
	else printf("NO\n");
}

int ctoi(char c) {
	return c - '0';
}

ll kai(ll x) {
	ll a = 1;
	if (x <= 0)
		return 1;
	else {
		for (ll i = 0; i < x; i++)
			a = a * (i + 1);
		return a;
	}
}

ll rui(ll x, ll y) {
	ll a = 1;
	for (ll i = 0; i < y; i++)
		a = a * x;
	return a;
}
const int nmax = 150;
int cccc[nmax][nmax];
ll comb(ll n, ll k) {
	if (n < k) {
		cout << "error n<k" << endl;
		return -1;
	}
	if (cccc[n][k] > 0)return cccc[n][k];
	if (k == 0 || n == k)return 1;
	return cccc[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
}

ll keta(ll a) {
	ll i = 1;
	while (1) {
		if (a < pow((ll)10, i))
			return i;
		i++;
	}
}
vector<ll> v;
ll n, m;
//m進数全探索
ll inc(ll a = n - 1) {
	if (a == 0 && v[0] == m) {
		v[0] = -1;
		return v[0];
	}
	if (v[a] == m) {
		v[a] = 0;
		inc(a - 1);
		return v[a];
	}
	else {
		++v[a];
		return v[a];
	}
}

ll mod = 1e9+7;

ll modkai(ll a) {
	ll ret = 1;
	rep(a) {
		ret *= (i + 1);
		ret %= mod;
	}
	return ret;
}

ll modpowl(ll a, ll b) {
	if (b == 0) {

		return 1;
	}
	if (b == 1) {

		return a;
	}
	if (b >= 2) {
		if (b % 2 == 0) {
			ll c = modpowl((a*a) % mod, b / 2);
			c = c % mod;

			return c;
		}
		else {
			ll c = (modpowl((a*a) % mod, b / 2) % mod)*a;
			c = c % mod;

			return c;
		}
	}
}
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod%i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

ll llpow(ll a, ll b) {
	if (b == 0) {

		return 1;
	}
	if (b == 1) {

		return a;
	}
	if (b >= 2) {
		if (b % 2 == 0) {
			ll c = llpow((a*a), b / 2);
			c = c;

			return c;
		}
		else {
			ll c = (llpow((a*a), b / 2))*a;
			c = c;

			return c;
		}
	}
}
std::vector<ll> Eratosthenes(ll N)
{
	std::vector<bool> is_prime(N + 1);
	for (ll i = 0; i <= N; i++)
	{
		is_prime[i] = true;
	}
	std::vector<ll> P;
	for (ll i = 2; i <= N; i++)
	{
		if (is_prime[i])
		{
			for (ll j = 2 * i; j <= N; j += i)
			{
				is_prime[j] = false;
			}
			P.emplace_back(i);
		}
	}
	return P;
}

int main() {
	ll n, k;
	cin >> n >> k;
	ll r, s, p;
	cin >> r >> s >> p;
	string t;
	cin >> t;
	ll ans = 0;
	int flag = 1;
	int flag2 = 1;
	int flag3 = 1;
	string te;
	rep(n) {
		if (i < k) {
			if (t[i] == 'r') {
				ans += p; te.push_back('p');
			}
			else if (t[i] == 's') {
				ans += r;
				te.push_back('r');
			}
			else {
				ans += s;
				te.push_back('s');
			}
		}
		else {
			if (t[i] == 'r') { 
				if (te[i - k] != 'p') {
					ans += p;
					te.push_back('p');
				}
				else te.push_back('a');
			}
			else if (t[i] == 's') {
				if (te[i - k] != 'r') {
					ans += r;
					te.push_back('r');
				}
				else te.push_back('a');
			}
			if (t[i] == 'p') {
				if (te[i - k] != 's') {
					ans += s;
					te.push_back('s');
				}
				else te.push_back('a');
			}
		}
	}
	cout << ans;
}