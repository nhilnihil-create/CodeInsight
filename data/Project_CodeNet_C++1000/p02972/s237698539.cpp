#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n + 1];
	int* b = new int[n + 1];
	for (int i = 0;i < n;i++) {
		cin >> a[i + 1];
	}
	for (int i = n;i >= 1;i--) {
		int ans = 0;
		for (int j = i * 2;j <= n;j += i) {
			ans += b[j];
			ans %= 2;
		}
		b[i] = (2 + a[i] - ans) % 2;
	}
	int kosuu = 0;
	for (int i = 1;i <= n;i++) {
		if (b[i] == 1)kosuu++;
	}
	cout << kosuu << endl;
	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		if (b[i] == 1) {
			if (cnt < kosuu - 1) {
				cout << i << " ";
				cnt++;
			}
			else {
				cout << i;
				break;
			}
			
		}
	}
}