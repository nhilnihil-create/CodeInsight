#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	vector<pair<int, int>> pa;
	for (int i = 0; i < n; i++) {
		ll x, L; cin >> x >> L;
		pa.push_back({ x + L ,x - L });	
	}
	sort(pa.begin(), pa.end());
	int cur = -1000000000;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (cur <= pa[i].second) {
			ans++;
			cur = pa[i].first;
		}
	}	
	cout << ans << endl;
	return 0;
}