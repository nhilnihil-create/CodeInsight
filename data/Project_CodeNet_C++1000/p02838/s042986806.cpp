#include<iostream>
using namespace std;
long long int a[300000];
long long int b[300000][60];
long long int c[60];
long long int sum;
long long int MOD = 1000000007;
int main() {

	//abc147_d
	long long int i, n, j;
	cin >> n;
	long long int bin[61];
	bin[0] = 1;
	for (i = 1; i < 61; i++) {
		bin[i] = bin[i - 1] * 2;
	}
	for (i = 0; i < n; i++) {
		cin >> a[i];
		j = 0;
		while (a[i] > 0) {
			if (a[i] % 2 == 1) {
				b[i][j] = 1;
				c[j]++;
			}
			else {
				b[i][j] = 0;
			}
			a[i] = a[i] / 2;
			j++;
		}
	}
	for (i = 0; i < 60; i++) {
		j = (c[i] * (n - c[i])) % MOD;
		j = (j * (bin[i] % MOD)) % MOD;
		sum = (sum + j) % MOD;
	}
	cout << sum << endl;
	return 0;
}