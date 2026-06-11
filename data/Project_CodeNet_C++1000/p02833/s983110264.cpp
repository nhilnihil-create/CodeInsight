#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ff first
#define ss second
#define endl '\n'

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	ll n;
	cin >> n;

	if (n & 1) {
		cout << 0 << endl;
		return 0;
	}

	n /= 2;
	ll ans = 0;
	for (n /= 5; n > 0; n /= 5) {
		ans += n;
	}

	cout << ans << endl;
	return 0;
}
