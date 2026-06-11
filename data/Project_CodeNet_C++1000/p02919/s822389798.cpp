// me & god
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

int n;
vector <pair <ll, ll>> v;
set <ll> s;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		v.push_back({a, i});
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ll a = v[i].second;
		ll b = v[i].first;
		s.insert(a);
		auto x = s.find(a);
		ll l1 = -1, l2 = -1, r1 = n, r2 = n;
		if (x != s.begin()) {
			x--;
			l1 = *x;
			if (x != s.begin()) {
				x--;
				l2 = *x;
			}
		}
		x = s.find(a);
		x++;
		if (x != s.end()) {
			r1 = *x;
			x++;
			if (x != s.end())
				r2 = *x; 
		}
		ll k = l1 - l2;
		ll p = r1 - a;
		ans += k * p * b;
		k = r2 - r1;
		p = a - l1;
		ans += k * p * b;
//		cout << ans << " ******" << endl;
//		cout << l1 << " " << l2 << "    " << r1 << " " << r2 << " &&&&" << endl;
	}
	cout << ans;
	return 0;
}