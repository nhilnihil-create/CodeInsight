#include<bits/stdc++.h>
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;
	ll a[n], b[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	if (n % 2)
	{
		ll y = a[n / 2];
		ll z = b[n / 2];
		cout << z - y + 1;
		return 0;
	}
	else
	{
		ll y = (a[n / 2 - 1] + a[n / 2]);
		ll z = (b[n / 2 - 1] + b[n / 2]);
		cout << z - y + 1;
		return 0;
	}
}

