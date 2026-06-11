#include <iostream>
#include <cstdio>
#include <map>
#define N 200005
using namespace std;

typedef long long ll;
ll n, k, ans, a[N];
map<ll, ll> c;
int main()
{
	ll i;
	cin >> n >> k;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] = (a[i - 1] + a[i]) % k;
	}
	for (i = 1; i <= n; i++) a[i] = (a[i] - i % k + k) % k;
	for (i = 1; i <= min(n, k - 1); i++) c[a[i]]++;
	ans += c[0];
	for (i = 1; i < n; i++) {
		c[a[i]]--;
		if (i + k - 1 <= n) c[a[i + k - 1]]++;
		ans += c[a[i]];
	}
    cout << ans << endl;
    return 0;
}