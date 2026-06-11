#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,k;
	cin >> n >> k;
	vector<ll> a(n);
	for(auto& e:a) cin >> e;
	ll ans = 0;
	
	sort(a.begin(), a.end(), greater<int>());
	for(int i=0; i<min(n,k); i++) {
		a[i] = 0;
	}
	
	
	for(int i=0; i<n; i++) {
		ans += a[i];
	}
	
	
	cout << ans << '\n';
	return 0;
}
