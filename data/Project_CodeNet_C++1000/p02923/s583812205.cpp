#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];
	
	int ans = 0, tmp = 0;
	for (int i = 0; i < n-1; i++) {
		if (h[i] >= h[i+1]) tmp++;
		else {
			ans = max(ans, tmp);
			tmp = 0;
		}
		if (i == n-2)
			ans = max(ans, tmp);
	}
	cout << ans << endl;
}