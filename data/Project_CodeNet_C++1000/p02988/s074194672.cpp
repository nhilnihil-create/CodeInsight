#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		cin >> ans[i];
	}
	int cnt = 0;
	for (int i = 1; i < n - 1; i++) {
		if (ans[i - 1] < ans[i] && ans[i] < ans[i + 1]) cnt++;
		else if (ans[i - 1] > ans[i] && ans[i] > ans[i + 1]) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}
