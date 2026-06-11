#include <bits/stdc++.h>
#include <stdint.h>
#define mod 1000000007
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define pi 3.1415926535897932
#define nui 100
using namespace std;

int main()
{

       ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n == 1)
	{
		cout << a[0] << "\n";
	}
	else
	{
		ld sum = 0;
		for (ll i = 0; i < n; i++)
		{
			sum += float(1) / float(a[i]);
		}
		ld res = float(float(1) / float(sum));
		cout << fixed << setprecision(4) << res << "\n";
	}
	return 0;
}

