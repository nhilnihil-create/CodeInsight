#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ll long long
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define ff first
#define ss second
#define prec(y,x) fixed<<setprecision(y)<<x
#define inf 1e18
#define pi 3.1415926535

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin >> n;
	ll ans = 1e13;
	ll q = sqrt(n);
	q += 2;
	for (int i = 1; i <= q; i++)
	{
		if (n % i == 0)
		{
			ll ans1 = i + n / i; ans1--; ans1--;
			ans = min(ans, ans1);
		}
	}
	cout << ans;
	return 0;
}