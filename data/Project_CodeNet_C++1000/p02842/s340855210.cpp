#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	double ans = n / 1.08;
	ll r = ceil(ans);
	if (floor(r * 1.08) != n)
		cout << ":(";
	else
		cout << r;
	return 0;
}
