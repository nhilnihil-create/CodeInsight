#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> p(n), min_p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];		
	}
	min_p[0] = p[0];
	for (int i = 1; i < n; i++) {
		min_p[i] = min(min_p[i - 1], p[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] <= min_p[i]) ans++;
	}
	cout << ans << endl;
    return 0;
}