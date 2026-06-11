#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_fizzbuzz_sum(void) {
	long long n;
	cin >> n;
	long long sum;
	sum = n * (n + 1) / 2;
	for (int i = 1; i <= n; i++) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			sum -= i;
		}
	}
	cout << sum << endl;
}

int main()
{
    b_fizzbuzz_sum();

    return 0;
}