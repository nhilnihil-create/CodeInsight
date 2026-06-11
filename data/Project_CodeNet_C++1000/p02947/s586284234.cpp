#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(n,x) for(ll i=0;i<n;i++) cin>>x[i];


int main()
{
	ll n;
	cin >> n;
	vector<string> k;
	string s;
	for (ll i = 0; i < n; i++)
	{
		cin >> s;
		sort(s.begin(), s.end());
		k.push_back(s);
	}
	sort(k.begin(), k.end());
	vector<ll> p(n, 1);
	string x = k[0];
	ll q = 0;
	for (ll i = 1; i < n; i++)
	{
		if (k[i - 1] == k[i]) p[q]++;
		else q++;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		if (p[i] != 0)
		{
			ans += p[i] * (p[i] - 1) / 2;
		}
	}
	cout << ans << "\n";
	return 0;
}