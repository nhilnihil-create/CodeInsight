#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll prime(ll x) {
	ll i;
	if (x < 2)return 0;
	else if (x == 2) return 1;
	if (x % 2 == 0) return 0;
	for (i = 3; i*i <= x; i += 2) {
		if (x%i == 0) return 0;
	}
	return 1;
}
ll N;
int main() {
	while (cin >> N) {
		if (N == 0){
			break;
	}
			ll cnt = 0;
		for (ll i = N + 1; i <= 2 * N; i++) {
			if (prime(i))cnt++;
		}
		cout << cnt << endl;
	}
}
