#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int k, x;
	cin >> k >> x;
	int n = k - 1;
	vector<int> ans;
	for (int i = x; i <= x + n; i++) {
		ans.push_back(i);
	}
	for (int i = x - n; i < x; i++) {
		ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	if (k == 1) cout << x << "\n";
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
