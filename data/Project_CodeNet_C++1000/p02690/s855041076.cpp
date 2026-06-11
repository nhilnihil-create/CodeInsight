#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	auto& in = cin;
	long long x;
	in >> x;
	long long maxVal = 1800;

	for (long long a = -maxVal; a <= maxVal; ++a) {
		for (long long b = -maxVal; b <= maxVal; ++b) {
			if ((pow(a, 5) - pow(b, 5)) == x) {
				cout << a << ' ' << b;
				return 0;
			}
		}
	}

	return 0;
}
