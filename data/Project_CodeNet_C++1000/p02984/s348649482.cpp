#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int n;
	cin >>n;
	vector<ll> a(n);
	ll sum = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	ll diff_eve = 0;
	ll diff_odd = 0;
	for(int i = 0; i < n / 2; ++i)
	{
		diff_eve += a[(i * 2 + 1) % n]; // i = 0
		diff_odd += a[(i * 2 + 2) % n]; // i = 1
	}

	for(int i = 0; i < n / 2; ++i)
	{
		/*
		for(int j = 0; j < n / 2; ++j)
		{
			diff += a[(i + 2 * j + 1) % n];
		}
		*/
		cout << sum - 2 * diff_eve << " " << sum - 2 * diff_odd << " ";// << endl;
		//cout << "eve: minus " << (i * 2 + 1) % n << " : plus " << (i * 2 + 1 + n/2*2) % n << endl;
		// cout << "odd: minus " << (i * 2 + 2) % n << " : plus " << (i * 2 + 2 + n/2*2) % n << endl;
		diff_eve += a[(i * 2 + 1 + n/2*2) % n] - a[(i * 2 + 1) % n];
		diff_odd += a[(i * 2 + 2 + n/2*2) % n] - a[(i * 2 + 2) % n];
	}
	if (n & 1)
	{
		// 最後表示されないので表示
		cout << sum - 2 * diff_eve;
	}


}

int main()
{
	fastio;
	solve();

	return 0;
}