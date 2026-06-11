#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	const int p = 9;
	string ans = "No";
	for (int i = 1; i <= p; i++) {
		for (int j = 1; j <= p; j++) {
			if (i * j == n) ans = "Yes";
		}
	}
	cout << ans << endl;
	return 0;
}