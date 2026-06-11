#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int k, q;
	cin >> k >> q;
	vector<ll> d(k);
	for(ll& x : d) cin >> x;
	
	for(int rep = 0; rep < q; rep++) {
		ll n, x, m;
		cin >> n >> x >> m;
		vector<ll> tmp_d(k), occur(k);
		for(int i = 0; i < k; i++) {
			tmp_d[i] = d[i] % m;
			occur[i] = (n-1)/k + (i < (n-1) % k);
		}
		
		ll a = x % m;
		for(int i = 0; i < k; i++) {
			a += tmp_d[i]*occur[i];
		}
		//$ cerr << a << endl;
		a /= m;
		for(int i = 0; i < k; i++) {
			if(tmp_d[i] == 0) {
				a += occur[i];
			}
		}
		
		cout << n - 1 - a << '\n';
	}
}
