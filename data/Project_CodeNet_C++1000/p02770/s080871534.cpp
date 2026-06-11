#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> ind, d;
int k;
int solve() {
	int n, x, m;
	cin >> n >> x >> m;
	n--;
	int tacc = 0, tzero = 0;
	for(int i=0; i<k; i++) {
		d[i] = ind[i] % m;
		tacc += d[i]*(n/k);
		if(i%k < n%k)
			tacc += d[i];
		if(!d[i]) {
			//printf("at i=%d, not di, add %d\n", i, n/k);
			tzero += n/k;
			if(i%k < n%k) {
				//printf("additional one\n");
				tzero++;
			}
		}
	}
	int tsub = (x+tacc)/m - x/m;
	//printf("tacc=%d, tsub=%d, zero=%d\n", tacc, tsub, tzero);
	return n - tsub - tzero;
	int acc = accumulate(d.begin(), d.end(), 0ll)*(n/k) + accumulate(d.begin(), d.begin()+(n%k), 0ll);
	int zero = count_if(d.begin(), d.end(), [](int t){return !t;})*(n/k) + count_if(d.begin(), d.begin()+(n%k), [](int t){return !t;});
	int sub = x/m + (x+acc)/m;
	//printf("acc=%lld, sub=%lld, zero = %lld\n", acc, sub, zero);
	return n-sub - zero;
}
int32_t main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int q;
	cin >> k >> q;
	ind.resize(k);
	d.resize(k);
	for(int i=0; i<k; i++) {
		cin >> ind[i];
	}
	while(q--)
		cout << solve() << '\n';
}