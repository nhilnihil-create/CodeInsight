#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n % 2 == 1) {
		for (int i = 1; i <= m; i++) {
			cout << i << ' ' << n+1-i << '\n';
		}
	} else {
		int a = n / 4;
		for (int i = 1; i <= m; i++) {
			if (i <= a) cout << i << ' ' << n+1-i << '\n';
			else cout << i << ' ' << n-i << '\n';
		}
	}
	return 0;
}