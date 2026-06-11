#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
using namespace std;
typedef long long  ll;

int main() {
	int n;
	vector<ll> A;
	ll ans = 0;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		A.emplace_back(x);
	}
	sort(A.begin(), A.end());
	for (int i = 1; i < n ; i++) {
			ans += A[n-1 - i / 2];
	}
	cout << ans;
	return 0;
}