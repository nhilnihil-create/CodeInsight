#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int A, B;
	cin >> A >> B;

	int ans = -1;
	for (int i = 1; i <= 1000; ++i) {
		double a = i * 0.08;
		double b = i * 0.1;

		if ((int)a == A && (int)b == B) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
