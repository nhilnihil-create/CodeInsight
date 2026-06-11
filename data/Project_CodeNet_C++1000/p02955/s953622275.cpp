#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, k, ans, sa, a[505], b[505];

bool f(ll p) {
	ll i, sb=0, sc=0;
	for(i=0; i<n; i++) b[i] = a[i]%p, sb += b[i];
	sort(b, b+n);
	for(i=0; i<n-sb/p; i++) sc += b[i];
	return sc<=k;
}

int main() {
	ll i;
	cin >> n >> k;
	for(i=0; i<n; i++) cin >> a[i], sa += a[i];
	for(i=1; i*i<=sa; i++) if(sa%i==0) {
		if(f(i)) ans = max(ans, i);
		if(f(sa/i)) ans = max(ans, sa/i);
	}
	cout << ans;
	return 0;
}