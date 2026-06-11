#include<iostream>
using namespace std;

int main() {

	int K;
	cin >> K;

	int ans = 0;
	int x = 7 % K;
	for (int i = 0; i < K; i++) {
		x = x % K;
		ans++;
		if (x == 0) {
			cout << ans << endl;
			return 0;
		}
		else {
			x = 10 * x + 7;
		}
	}

	cout << -1 << endl;

	return 0;
}