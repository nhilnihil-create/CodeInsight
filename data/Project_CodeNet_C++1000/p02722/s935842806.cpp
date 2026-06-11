#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <utility>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long int ll;
const ll mod = 998244353;
const ll INF = 1e9 + 5;

ll check(ll n, ll i)
{
	while (n % i == 0)
		n /= i;
	if (n % i == 1)
		return 1;
	else
		return 0;
}

void solve()
{
	ll n, k, cnt=2;
	cin >> n;
	k = n - 1;
	if (n <= 4)
	{
		if (n == 2)
		{
			cout << 1 << endl;
			return;
		}
		if (n == 3)
		{
			cout << 2 << endl;
			return;
		}
		if (n == 4)
		{
			cout << 3 << endl;
			return;
		}
	}

	for (ll i = 2; i <= sqrt(k); i++)
		if (k % i == 0 && i != sqrt(k))
			cnt += 2;
		else if (i == sqrt(k))
			cnt++;

	for (ll i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			if (check(n, i))
				cnt++;

	cout << cnt << endl;
}

int main()
{
//	int t;
//	cin >> t;
//	while(t-->0)
	solve();
}