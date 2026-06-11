#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	
	int n;
	cin >> n;
	vector<int>a(n);
	for(auto& e:a) cin >> e;
	ll ans = 0;
	for(int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			ans += a[i]*a[j];
		}
	}
	cout << ans << '\n';
	
	return 0;
}
