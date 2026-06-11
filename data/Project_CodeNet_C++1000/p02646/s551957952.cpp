#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll x1, s1, x2, s2, t;
	cin >> x1 >> s1 >> x2 >> s2 >> t;

	if (s1 <= s2) {
		cout << "NO\n";
	}
	else {
		ll d = s1 - s2;

		if (abs(x1 - x2) <= t * d)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}