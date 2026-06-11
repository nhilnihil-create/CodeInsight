#include <iostream>
using namespace std;

const int nmax = 123456;
int n, sosu[nmax * 2 + 1], c = 0;

void set() {
	for (int i = 2; i <= nmax; i++) {
		if (sosu[i] == 0) {
			for (int j = 2; i*j <= nmax * 2; j++) {
				sosu[i*j] = 1;
			}
		}
	}
}

int main() {
	set();

	while (true) {
		cin >> n;
		if (n == 0)break;
		for (int i = n + 1; i <= n * 2; i++) {
			if (sosu[i] == 0)c++;
		}

		cout << c << endl;
		c = 0;
	}
}