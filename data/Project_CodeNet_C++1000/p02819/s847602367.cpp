#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(void) {
	long X;
	scanf("%ld", &X);
	int i = 0;
	while (1) {
		bool isPrime = true;
		for (long j = 2; j*j < X + i; j++) {
			// cout << X + i << " " << j << endl;
			if ((X + i) % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			printf("%ld", X + i);
			return 0;
		}
		i++;
	}

	return 0;
}
