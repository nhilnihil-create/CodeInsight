#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, k; cin >> n >> k;
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i + 1] != s[i]) cnt++;
	}
	int ans = n - 1 - max(cnt - 2 * k, 0);
	
	cout << ans << endl;
	return 0;
}
