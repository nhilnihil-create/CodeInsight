#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	if ((b - a) % 2 == 1) {
		ll x = min(a - 1, n - b) + 1 + (b-a-1)/2;
		cout << x << endl;
	}
	else {
		ll y = (b - a) / 2;
		cout << y << endl;
	}
}