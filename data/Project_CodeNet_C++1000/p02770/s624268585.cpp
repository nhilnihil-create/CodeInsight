#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> ind, d;
int k;
int solve() {
	int n, x, m;
	cin >> n >> x >> m;
	n--;
	for(int i=0; i<k; i++) {
		d[i] = ind[i] % m;
	}
	int acc = accumulate(d.begin(), d.end(), 0ll)*(n/k) + accumulate(d.begin(), d.begin()+(n%k), 0ll);
	int zero = count_if(d.begin(), d.end(), [](int t){return !t;})*(n/k) + count_if(d.begin(), d.begin()+(n%k), [](int t){return !t;});
	int sub = (x+acc)/m - x/m;
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