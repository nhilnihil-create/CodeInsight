#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll n, k, t, ans, a[200005];
map<ll, ll> mp;
int main() {
	cin >> n >> k;
	mp[0] = 1;
	for(ll i=1; i<=n; i++) {
		if(i>=k) mp[a[i-k]]--;
		scanf("%lld", &t);
		a[i] = (a[i-1] + t-1) % k;
		ans += mp[a[i]]++;
	}
	cout << ans;
	return 0;
}