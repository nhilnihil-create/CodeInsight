#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;

int main(){
	int n; ll D, A; scanf("%d %lld %lld", &n, &D, &A);
	vector<P> a(n);
	for(int i = 0; i < n; i++) scanf("%lld %lld", &a[i].first, &a[i].second);
	sort(a.begin(), a.end());
	vector<ll> x(n), h(n), cnt(n + 1, 0);
	for(int i = 0; i < n; i++) x[i] = a[i].first, h[i] = a[i].second;
	ll ans = 0, id = 0;
	for(int i = 0; i < n; i++){
		if(i != 0) cnt[i] += cnt[i - 1];
		h[i] -= cnt[i] * A;
		if(h[i] <= 0) continue;
		ll num = (h[i] + A - 1) / A;
		ans += num;
		cnt[i + 1] += num;
		while(x[id] - x[i] <= 2 * D && id < n) id++;
		cnt[id] -= num;
	}
	printf("%lld\n", ans);
}