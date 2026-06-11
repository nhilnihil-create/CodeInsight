#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set> 
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <iomanip>
#include <complex>
#define assem99 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define ld long double
#define ii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<ii>
#define point complex<double>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define F first
#define S second
#define sz(a) (int)(a).size()
#define ReadFile freopen("input.txt","r",stdin)
#define WriteFile freopen("output.txt","w",stdout)
int x[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int y[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
const int MOD = 1e9 + 7, N = 1e5 + 5;
const double pi = acos(-1);
using namespace std;

ll fact[N], inv[N];
ll fp(ll b, ll p)
{
	if (p == 0)
		return 1;
	ll ans = fp(b, p / 2);
	ans = (ans * ans) % MOD;

	if (p % 2 != 0)
		ans = (ans *(b % MOD)) % MOD;
	return ans;
}

void calc(ll n)
{
	fact[0] = inv[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		fact[i] = (i * fact[i - 1]) % MOD;
		inv[i] = fp(fact[i], MOD - 2);
	}
}

ll ncr(ll n, ll r)
{
	return ((fact[n] * inv[r]) % MOD * inv[n - r]) % MOD;
}

int main()
{
	assem99;
	calc(N - 1);
	ll n, k; cin >> n >> k;
	rep(i, 1, k + 1)
	{
		if (n - k + 1 >= i)
		{
			ll ans = ncr(n - k + 1, i) % MOD;
			ans *= (ncr(k - 1, i - 1) % MOD) ;
			ans %= MOD;
			cout << ans << endl;
		}
		else cout << "0" << endl;
	}

	return 0;
}