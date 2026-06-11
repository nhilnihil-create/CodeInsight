//Sum of two integers
#include <iostream>
using namespace std;
int main() {
	long long n;
	cin >> n;
	if (n & 1)
		cout << n / 2 << endl;
	else
		cout << (n / 2) - 1 << endl;
	return 0;
} 