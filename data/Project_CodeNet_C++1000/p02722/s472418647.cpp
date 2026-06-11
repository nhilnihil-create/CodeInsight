#include<iostream>
#include<math.h>
using namespace std;
int main() {
	long long int n;
	cin >> n;
	if (n == 2) {
		cout << 1 << endl;
		return 0;
	}
	int counter = 0;
	long long int nn;
	long long int i;
	for (i = 2; i <= sqrt(n); i++) {
		//cout << sqrt(n);
		//cout << n - 1 <<':' << i << endl;
		if (((n - 1) % i) == 0) {
			counter = counter + 2;
			//cout << 'a' << i << endl;
			if (i * i == n - 1) {
				counter = counter - 1;
			}
		}
		if (n % i == 0) {
			nn = n;
			while (nn % i == 0) {
				nn = nn / i;
			}
			if (nn % i == 1) {
				//cout << 'i' << i << endl;
				counter++;
			}
		}
		//cout << "i:" << i << endl;
	}
	counter=counter+ 2;
	cout << counter << endl;
	return 0;
}