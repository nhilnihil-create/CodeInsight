#include <iostream>
using namespace std;

int main() {
	int n, a, b, temp_a, temp_b;	
	while (cin >> n) {
		a = 0; b = 0; if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> temp_a >> temp_b;
			if (temp_a == temp_b) {
				a = a + temp_a; b = b + temp_b;
			}
			else {
				a = a + (temp_a > temp_b ? temp_a + temp_b : 0);
				b = b + (temp_a < temp_b ? temp_a + temp_b : 0);
			}
		}
		cout << a << " " << b << endl;
	}
	return 0;
}
