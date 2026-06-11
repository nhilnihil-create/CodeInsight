#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	ll res = a * b / ll(__gcd(a, b));
	cout << res << endl;
	return 0;
}