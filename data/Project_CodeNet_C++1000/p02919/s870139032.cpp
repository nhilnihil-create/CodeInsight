#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	vector<long long> v(n+1), dpl(n+1), dpl2(n+1), dpr(n+1, n+1), dpr2(n+1, n+1), where(n+1);
	set<long long> pst;
	for(int i=1; i<=n; i++) {
		cin >> v[i];
		where[v[i]] = i;
	}
	for(int i=n; i>=1; i--) {
		auto it = pst.lower_bound(where[i]);
		if(it != pst.end()) {
			dpr[where[i]] = *it;
			if(next(it) != pst.end()) {
				dpr2[where[i]] = *next(it);
			}
		}
		if(it != pst.begin()) {
			it--;
			dpl[where[i]] = *it;
			if(it != pst.begin()) {
				dpl2[where[i]] = *prev(it);
			}
		}
		pst.insert(where[i]);
	}
	long long ans = 0;
	for(int i=1; i<=n; i++) {
		//printf("at i=%d, dpl2, dpl = %lld, %lld  dpr, dpr2=%lld, %lld\n", i, dpl2[i], dpl[i], dpr[i], dpr2[i]);
		//printf("added is %lld * %lld * %lld\n", v[i], (i-dpl[i]));
		ans += v[i]*((i-dpl[i])*(dpr2[i]-dpr[i]) + (dpr[i]-i)*(dpl[i]-dpl2[i]));
	}
	cout << ans;
}