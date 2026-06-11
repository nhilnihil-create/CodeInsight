#include<iostream>
using namespace std;

int isPrime(int n) {
	int cnt = 0;
	for(int k= n+1;k<=2*n;k++){
		for (int i = 2; i*i <= k; i++) {
			if (k%i == 0) {
				cnt++;
				break;
			}
		}
	}

	cout << (2*n)-(n)-cnt << endl;
	return cnt;
}

int main() {
	
	while (1) {
		int n;

		cin >> n;

		if (n == 0)
			break;

		isPrime(n);

	}
	return 0;
}