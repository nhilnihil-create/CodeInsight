#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_golden_apple(void) {
	int n, d;
	cin >> n >> d;

	int cnt = 0;

	int div = (d << 1) + 1;

	if (n % div == 0) {
		cnt = n / div;
	}
	else {
		cnt = n / div + 1;
	}

	cout << cnt << endl;
}

int main()
{
    b_golden_apple();

    return 0;
}