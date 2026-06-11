#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll res = max({a * c, b * d, a * d, b * c});
	cout << res << '\n';

	return 0;
}