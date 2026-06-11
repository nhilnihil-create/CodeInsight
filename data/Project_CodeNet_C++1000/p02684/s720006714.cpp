#include<bits/stdc++.h>
using namespace std;
#define ll         long long
#define mod        1000000007
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf        1e18
#define ps(x,y)    fixed<<setprecision(y)<<x

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	ll n, k;
	cin >> n >> k;
	ll a[n + 1];
	a[0] = 0;
	for (ll i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	std::vector<ll> v(n + 1, 0);

	ll start = 1;
	int l ;
	while (1)
	{
		if (v[start] == 1)
		{
			l = start;
			break;
		}

		v[start] = 1;
		start = a[start];
		k--;
		if (k == 0)
		{
			cout << start << endl;
			return 0;
		}
	}

	ll cnt = 0;
	int end = start;
	vector<int > v1;
	while (1)
	{

		v1.push_back(start);
		start = a[start];
		cnt++;
		if (start == end)
			break;
	}
	// for (auto i : v1)
	// {
	// 	cout << i << " ";
	// }
	cout << v1[k % cnt] << endl;
}