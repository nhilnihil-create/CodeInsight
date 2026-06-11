#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	Int X;
	cin >> X;

	int ans = 0;
	Int sum = 100;
	while (sum < X) {
		sum = sum + sum / 100;
		++ans;
	}
	cout << ans << endl;

	return 0;
}
