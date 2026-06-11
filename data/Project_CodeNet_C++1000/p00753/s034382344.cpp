#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	int sosu[250000] = { 0 };
	for (int i = 2; i < 250000; i++) {
		for (int j = 2; i*j < 250000; j++) {
			sosu[i*j] = 1;
		}
	}

	for (;;) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}

		int count = 0;
		for (int i = n + 1; i <= 2*n; i++) {
			if (sosu[i] == 0) {
				count++;
			}
		}
		printf("%d\n", count);
	}
}