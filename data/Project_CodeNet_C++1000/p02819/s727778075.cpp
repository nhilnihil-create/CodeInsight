#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(void) {
	long X;
	scanf("%ld", &X);
	while (1) {
		bool isPrime = true;
		for (long j = 2; j*j < X; j++) {
			// cout << X + i << " " << j << endl;
			if (X % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			printf("%ld", X);
			return 0;
		}
		X++;
	}

	return 0;
}
