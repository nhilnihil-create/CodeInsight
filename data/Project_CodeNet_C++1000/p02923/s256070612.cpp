#include "bits/stdc++.h"
using namespace std;

//46
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int ans = 0;
	int cnt = 0;
	for (int i = 1; i < n; ++i) {
		if (v[i] <= v[i - 1]) {
			cnt++;
		}else {
			cnt = 0;
		}
		ans = max(ans,cnt);
	}
	cout << ans;
}
