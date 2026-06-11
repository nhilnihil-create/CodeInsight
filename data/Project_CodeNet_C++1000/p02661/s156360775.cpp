#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<ll>a(n);
	vector<ll>b(n);
	for (int i = 0; i < n; i++)cin >> a.at(i) >> b.at(i);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll x = n % 2;
	if (x == 0) cout << b.at(n / 2 - 1) + b.at(n / 2) - a.at(n / 2 - 1) - a.at(n / 2) + 1 << endl;
	else cout << b.at(n / 2) - a.at(n / 2) + 1 << endl;
}