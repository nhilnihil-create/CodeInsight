#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int x, y; cin >> x >> y;
	string ans = "No";
	if (y % 2 == 1) {
		cout << ans << endl;
		return 0;
	}
	if (2 * x <= y && y <= 4 * x) ans = "Yes";
	cout << ans << endl;
    return 0;
}