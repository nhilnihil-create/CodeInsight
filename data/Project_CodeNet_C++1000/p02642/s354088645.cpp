#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	const int p = 1000005;
	vector<int> num(p, 0);
	for (int i = 0; i < n; i++) {
		if (num[a[i]] != 0) {
			num[a[i]] = 2;
		}
		else {
			for (int j = a[i]; j < p; j += a[i]) {
				num[j]++;
			}
		}
	}
	int ans = 0;
	for (int x : a) {
		if (num[x] == 1) ans++;
	}
	cout << ans << endl;
    return 0;
}