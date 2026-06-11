#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	double ans;
	if (n % 2 == 0) ans = 0.5;
	else {
		int tmp = n / 2 + 1;
		ans = (double)tmp / n;
	}
	cout << fixed << setprecision(11) << ans << endl;
	return 0;
}