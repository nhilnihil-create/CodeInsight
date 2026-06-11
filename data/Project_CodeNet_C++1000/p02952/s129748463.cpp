#include<iostream>
using namespace std;

int calc(int x) {
	int cnt = 0;
	while (x) {
		x /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	int n; cin >> n;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = calc(i);
		if (tmp % 2 != 0)ans++;
	}
	cout << ans << endl;

	return 0;
}