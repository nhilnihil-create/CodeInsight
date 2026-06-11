#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	sort(a.begin(), a.end());
	if (a.at(0) == 0 && a.at(n - 1) == 0) {
		cout << "Yes" << endl;
		return 0;
	}
	if (n % 3 == 0) {
		if (a.at(0) == a.at(n / 3 - 1)
			&& a.at(n / 3 - 1) != a.at(n / 3)
			&& a.at(n / 3) == a.at(n * 2 / 3 - 1)
			&& a.at(n * 2 / 3 - 1) != a.at(n * 2 / 3)
			&& a.at(n * 2 / 3) == a.at(n - 1)) {
			bool xo = false;
			bitset<40>x(a.at(0));
			bitset<40>y(a.at(n / 3));
			bitset<40>z(a.at(n * 2 / 3));
			bitset<40>ze(0);
			bitset<40>ans = x ^ y;
			ans = ans ^ z;
			if (ans == ze)xo = true;
			if (xo)cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else if (a.at(0)==0
			&&a.at(0) == a.at(n / 3 - 1) 
			&&a.at(n/3-1)!=a.at(n/3)
			&& a.at(n / 3) == a.at(n - 1))cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else cout << "No" << endl;
}