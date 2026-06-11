#include <bits/stdc++.h>
using namespace std;

int main() {
	int aa, bb, mm;
	cin >> aa >> bb >> mm;
	vector<int> a(aa), b(bb);
	for (int i = 0; i < aa; i++) cin >> a[i];
	for (int i = 0; i < bb; i++) cin >> b[i];
	vector<array<int,3>> m(mm);
	for (int i = 0; i < mm; i++)
		cin >> m[i][0] >> m[i][1] >> m[i][2];

	int ans = INT_MAX;
	for (int i = 0; i < mm; i++) {
		int tmp = a[m[i][0]-1] + b[m[i][1]-1] - m[i][2];
		ans = min(ans, tmp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ans = min(ans, a[0]+b[0]);
	ans = max(0, ans);

	cout << ans << endl;

}