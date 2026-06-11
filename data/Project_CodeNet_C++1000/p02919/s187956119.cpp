#include<iostream>
#include<algorithm>
#include<functional>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int max_n = 1e5 + 100;
pii a[max_n];
int n;
ll ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a[i].first;
		a[i].second = i;
	}sort(a, a + n, greater<pii>());
	set<ll> myset;
	for (int i = 0;i < n;i++) {
		if (myset.empty()) {
			myset.insert(a[i].second);
			continue;
		}
		if (myset.size() == 1) {
			ll x = *myset.begin();
			ll y = a[i].second;
			if (x > y) { x = x ^ y;y = x ^ y;x = x ^ y; }
			ans += (x + 1) * (n - y) * a[i].first;
			myset.insert(a[i].second);
			continue;
		}
		set<ll>::iterator fr = myset.lower_bound(a[i].second);
		if (fr == myset.end()) {
			set<ll>::iterator be = --fr;
			ll right = n;ll x = *be;
			ll left = *(--be);ll y = a[i].second;
			ans += (x - left) * (right - y) * a[i].first;
		}
		else if (fr == myset.begin()) {
			ll left = -1;ll x = a[i].second;
			ll y = *fr;ll right = *(++fr);
			ans += (x - left) * (right - y) * a[i].first;
		}
		else {
			set<ll>::iterator be = --fr;fr++;
			ll behind = *be;ll front = *fr;
			ll left;ll right;
			if (be == myset.begin())left = -1;
			else left = *(--be);
			if (fr == --myset.end())right = n;
			else right = *(++fr);
			ll x = behind;ll y = a[i].second;
			ans += (x - left) * (front - y) * a[i].first;
			x = a[i].second;y = front;
			ans += (x - behind) * (right - y) * a[i].first;
		}myset.insert(a[i].second);
	}cout << ans << endl;
}