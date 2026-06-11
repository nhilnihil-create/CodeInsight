#include <iostream>
using namespace std;

int main() {
	int n, m, a, b = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		b = b + a;
	}
	if (n < b) {
		cout << "-1\n";
	}
	else {
		cout << n - b << "\n";
	}
	return 0;
}