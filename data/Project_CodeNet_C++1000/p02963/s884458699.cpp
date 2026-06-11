#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	if (n % 1000000000 == 0) {
		cout << "0 0 1000000000 1 " << 0 << " " << n / 1000000000 << endl;
	} else {
		cout << "0 0 1000000000 1 " << 1000000000 - (n % 1000000000) << " " << (n + 999999999) / 1000000000 << endl;
	}

	return 0;
}