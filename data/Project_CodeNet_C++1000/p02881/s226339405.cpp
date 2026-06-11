#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin >> n;
	ll q = sqrt(n + 0.5);
	for (ll i = q; i >= 1; --i) {
		if (n % i == 0) {
			cout << i + n / i - 2 << endl;
			return 0;
		}
	}
	return 0;
}