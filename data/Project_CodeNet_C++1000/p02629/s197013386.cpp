//Practice
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
const ll INF = 1e9 + 5;
const ll mxN = 1000000007;
const double E = 1e-9;

//------------------------------------------------------------------------------
ll n;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	/*vector<ll> a;
	for(ll i=26; i<=1000000000000001; i*=26)
		a.push_back(i);*/
	cin >> n;
	string ans = "";
	while (n > 0)
	{
		--n;
		ans += (n % 26) + 'a';
		n /= 26;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
//29-08-2020 10:40:06
//------------------------------------------------------------------------------