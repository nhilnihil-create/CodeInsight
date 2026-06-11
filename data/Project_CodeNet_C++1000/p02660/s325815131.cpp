#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	long long ret = 0;
	long long a = sqrt(n);
	for (long long i = 2; i < a; ++i) {
		long long count = 0;
		long long check = 1;
		long long check2 = 2;
		while (n % i == 0) {
			n /= i;
			++count;
			if (count == check) {
				++ret;
				check = check + check2++;
			}
		}
	}
	if (n != 1) {
		++ret;
	}

	cout << ret << endl;

	return 0;
}