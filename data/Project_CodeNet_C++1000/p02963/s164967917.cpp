#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll s, INF = 1e9;
	cin >> s;
	ll y = (s+INF-1)/INF;
	ll x = y*INF-s;
	cout << "0 0 1000000000 1 " << x << " " << y;
	return 0;
}
