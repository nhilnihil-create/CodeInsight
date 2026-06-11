#include <iostream>
using namespace std;

int main() {
	int q[10001], w[10001];
	
	int x = 1;
	while (1) {
		int n;
		int a = 0;
		int b = 0;
		cin >> n;
		if (n == 0) {
			break;
		}

		for (int i = 1; i <= n; ++i) {
			int c, d;
			cin >> c >> d;
			if (c == d) {
				a = a + c;
				b = b + d;
			}
			else if (c > d) {
				a = a + c + d;
			}
			else {
				b = b + c + d;
			}
		}
		q[x] = a;
		w[x] = b;
		x = x + 1;
	}
	for (int j = 1; j <= x-1; ++j) {
		cout << q[j]<<" "<< w[j] << endl;
	}
}