#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n) {
	if (n == 2)return true;
	if (n % 2 == 0)return false;
	for (int i = 3; i <= sqrt(n); i += 2) if (n%i == 0)return false;
	return true;
}
int main() {
	int n;
	while (cin >> n) {
		if (!n)return 0;
		int sum = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (isprime(i))sum++;
		}
		cout << sum << endl;
	}
}