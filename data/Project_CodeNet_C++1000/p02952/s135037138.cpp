#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//  2進数ならば baseNumber を  2 とする
// 10進数ならば baseNumber を 10 とする
int GetDigitsCount(int targetNumber, int baseNumber=10) {
	int digitsCount = 0;
	while (targetNumber != 0) {
		digitsCount++;
		targetNumber /= baseNumber;
	}
	return digitsCount;
}

int main() {

	int n, c; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (GetDigitsCount(i) % 2 == 1) ans++;
	}
	cout << ans << endl;
	return 0;
}