#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Vec = vector<int>;
using Graph = vector<Vec>;
#define INF 1000000007
#define MOD 1000000007
#define SEP " "

int		main(void)
{
	ll n, a, b;
	cin >> n >> a >> b;
	ll ans = (b - a) / 2;
	if ((b - a) % 2 == 1)
	{
		if (b-1 < n-a)
			ans += a;
		else
			ans += n-b + 1;
	}
	cout << ans << endl;
}
