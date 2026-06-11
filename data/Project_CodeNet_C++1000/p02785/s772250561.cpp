#include"bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
	ll n,k;
	cin >> n >> k;
	vector<ll> h(n);

	for (int i = 0; i < n;i++) {
		cin >> h[i];
	}

	if (n <= k) {
		cout << 0 << endl;
		return 0;
	}

	sort(h.begin(),h.end());

	ll count=0;

	for (int i = 0; i < n - k;i++) {
		count += h[i];
	}

	cout << count << endl;

	return 0;
}