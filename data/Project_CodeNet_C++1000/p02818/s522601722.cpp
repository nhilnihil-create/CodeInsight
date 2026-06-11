#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll a, b, k;
	cin >> a >> b >> k;
	if (a < k) {
		cout << 0 << " " << max(0ll, b - k + a) << endl;
	}
	else {
		cout << (a - k) << " " << b << endl;
	}
}
