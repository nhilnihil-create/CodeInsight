#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	if (n % 2) {
		cout << 0 << endl;
		return 0;
	}
	ll k = 5;
	ll ans = 0;
	while (k <= n) {
		ans += n / k / 2;
		k *= 5;
	}
	cout << ans << endl;
}