#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	int ans = -1;
	for (int i = n * 0.9; i <= n; i++) {
		if ((int)(1.08 * i) == n) {
			ans = i;
		}
	}
	if (ans == -1) cout << ":(" << endl;
	else cout << ans << endl;
    return 0;
}