#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define F first
#define S second
#define N 200005
using namespace std;

typedef long long ll;
ll n, ts, d, A, ans;
vector<ll> b, s;
pair<ll, ll> a[N];

ll g(ll p, ll q) {
	ll u = p / q;
	if (p % q) u++;
	return u;
}
int main()
{
	ll i, j, t, num, e;
	cin >> n >> d >> A;
	for (i = 0; i < n; i++) {
		scanf ("%lld %lld", &a[i].F, &a[i].S);
	}
	sort(a, a + n);
	for (i = 0; i < n; i++) {
		num = 0;
		if (!b.empty()) {
			t = lower_bound(b.begin(),b.end(), a[i].F - d) - b.begin();
			if (t > 0) num = s[t - 1];
		}
		a[i].S -= (ts - num);
		if (a[i].S > 0) {
            e = g(a[i].S, A);
            ans += e;
            b.push_back(a[i].F + d);
            ts += e * A;
            s.push_back(ts);
		}
	}
	cout << ans << endl;
    return 0;
}
