#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define mem(a,val) memset(a,val,sizeof(a))
#define ps(x,noOfDecimal) fixed<<setprecision(noOfDecimal)<<x

using namespace std;
vector<ll> printDivisors(ll n)
{
	vector<ll> a;

	// Note that this loop runs till square root
	for (ll i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			// If divisors are equal, print only one
			if (n / i == i)
				// printf("%d ", i);
				a.push_back(i);

			else // Otherwise print both
				// printf("%d %d ", i, n/i);
			{
				a.push_back(i);
				a.push_back(n / i);
			}
		}
	}
	return a;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	int t = 1;
	// cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		vector<ll> adiv, bdiv;
		adiv = printDivisors(a);
		bdiv = printDivisors(b);
		// sort(adiv.begin(), adiv.end());
		// sort(bdiv.begin(), bdiv.end());

		map<int, int> m;
		vector<ll> val;
		for (int i = 0; i < adiv.size(); ++i)
		{
			m[adiv[i]]++;
		}
		for (int i = 0; i < bdiv.size(); ++i)
		{
			// m[bdiv[i]]++;
			if (m[bdiv[i]] > 0)val.push_back(bdiv[i]);
		}

		int nn = val.size();
		vector<int> dp(nn, 1);

		for (int i = 0; i < nn; i++) {
			for (int j = 0; j < nn; j++) {
				if (i != j) {
					if (val[i] % val[j] == 0 && val[j] != 1) {
						dp[i]++;
					}
				}
			}
		}
		int chk = 0;
		for (int i = 0; i < dp.size(); i++) {
			// cout << dp[i] << " ";
			if (dp[i] == 1) {
				chk++;
			}
		}
		// cout << endl;
		cout << chk;
	}
	return 0;
}