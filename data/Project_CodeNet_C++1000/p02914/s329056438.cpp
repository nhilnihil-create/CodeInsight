#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll s = 0;
	for (int i = 0; i < n; i++) {
		s ^= a[i];
	}
	ll ans = s;
	for (int i = 0; i < n; i++) {
		a[i] &= ~s;
	}

	int r = 0;
	vector<int> top(n);
	for (int i = 60; i >= 0; i--) {
		int j = r;
		for (; j < n; j++) {
			if(a[j] >> i & 1) {
				swap(a[r], a[j]);
				break;
			}
		}
		if (j == n) {
			continue;
		}
		top[r] = i;
		for (int k = 0; k < n; k++) {
			if (r == k) {
				continue;
			}
			if (a[k] >> i & 1) {
				a[k] ^= a[r];
			}
		}
		r++;
	}

	ll x = 0;
	for (int i = 60; i >= 0; i--) {
		ll nx = x | (1ll << i);
		ll b = nx;
		for (int j = 0; j < r; j++) {
			if (b >> top[j] & 1) {
				b ^= a[j];
			}
		}
		if ((b & nx) == 0) {
			x = nx;
		}
	}
	ans += x * 2;
	cout << ans << endl;
	return 0;
}