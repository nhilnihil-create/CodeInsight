#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int x; cin >> x;
	int ans = 0;
	for (int i = 1; i <= x / 10; i++) {
		if (100 * i <= x && x <= 105 * i) {
			ans = 1;
			break;
		}
	}
	cout << ans << endl;
    return 0;
}