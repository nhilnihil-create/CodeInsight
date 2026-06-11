#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	int index = 0;
	int cnt = 1;
	while (true) {
		if (index == n) {
			break;
		}

		if (a[index] == cnt) {
			cnt++;
		}
		else { 
			ans++;			
		}
		index++;
	}

	if (cnt != 1) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}