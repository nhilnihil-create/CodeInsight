#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Max = 200005;
map <ll, ll> m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, a[Max], adun[Max], scad[Max];
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		adun[i] = i + a[i];
		scad[i] = i - a[i];
		m[adun[i]]++;
	}
	ll ans = 0;
	for (int i=1; i<=n; i++) {
		ans += m[scad[i]];
	}
	cout << ans;
	return 0;
}