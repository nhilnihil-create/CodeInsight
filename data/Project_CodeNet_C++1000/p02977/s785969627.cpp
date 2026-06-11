#include <iostream>

using namespace std;

int n;

int main() {
	cin >> n;
	int b = 1;
	while (b*2 <= n) b *= 2;
	if (n == b) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	cout << "1 2\n";
	cout << "2 3\n";
	cout << "3 " << n+1 << "\n";
	cout << n+3 << " " << 1 << "\n";
	cout << n+2 << " " << n+3 << "\n";
	for (int k = 4; k+1 <= n; k += 2) {
		cout << "1 " << k << "\n";
		cout << k << " " << k+1 << "\n";
		cout << "1 " << n+k+1 << "\n";
		cout << n+k+1 << " " << n+k << "\n";
	}
	if (n%2 == 0) {
		int x = 1^n^b;
		int y = 1;
		cout << x+n << " " << n << "\n";
		cout << b << " " << 2*n << "\n";
	}
}
