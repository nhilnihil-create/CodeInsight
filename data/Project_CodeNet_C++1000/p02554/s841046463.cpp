#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
ll n;

ll up(ll x, ll k)
{
	ll res = 1;
	while (k--)
		res = (res * x) % MOD;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cout << (up(10, n) - 2 * up(9, n) + up(8, n) + 10 * MOD) % MOD;
}