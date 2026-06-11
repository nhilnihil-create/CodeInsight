/******************************************
* AHAM BRAHMASHMI ;) *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod 1000000007


void print_vec(vll a)
{
	cout << "start printing the vector\n";
	for (ll i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << "\n";
}
void print_mat(vector<vll> a)
{
	cout << "start printing the matrix\n";
	for (ll i = 0; i < a.size(); i++)
	{
		for (ll j = 0; j < a[i].size(); j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

/******************************************
* NUMBER THEORY ;) *
******************************************/



ll powermod(ll x, ll y)
{
	ll res = 1;
	x = x % mod;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % mod;
		y = y >> 1;
		x = (x * x) % mod;
	}
	res %= mod;
	return res;
}
ll factmod(ll n)
{
	ll res = 1;
	while (n > 1)
	{
		res = (res * ((n / mod) % 2 ?  mod - 1 : 1)) % mod;
		for (ll i = 2; i <= n % mod; ++i)
			res = (res * i) % mod;
		n /= mod;
	}
	res %= mod;
	return res;
}



void solve()
{
	ll a, b;
	cin >> a >> b;
	ll gcd = __gcd(a, b);
	ll lcm = (a * b) / gcd;
	cout << lcm << "\n";

}

int main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// ll t;
	// cin>>t;
	// while(t--)
	// {
	solve();
	// }

	return 0;
}