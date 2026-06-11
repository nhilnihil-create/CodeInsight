#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("_in" , "r", stdin );
	freopen("_out", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n - 2; i++)
	for (int j = i + 1; j < n - 1; j++) {
		int dk1 = upper_bound(a.begin() + j + 1, a.end(), a[i] - a[j]) - a.begin();
		int dk2 = upper_bound(a.begin() + j + 1, a.end(), a[j] - a[i]) - a.begin();
		int dk3 = lower_bound(a.begin() + j + 1, a.end(), a[i] + a[j]) - a.begin();
		ans += dk3 - max(dk1, dk2);
	}
	cout << ans << '\n';
}
