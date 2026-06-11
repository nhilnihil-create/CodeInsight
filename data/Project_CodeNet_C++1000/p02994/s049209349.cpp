#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_bite_eating(void) {
	int n, l;
	cin >> n >> l;

	int taste;
	int sum = 0;
	int taste_abs_min = 10000;
	for (int i = 1; i <= n; i++) {
		taste = l + i - 1;
		sum += taste;

		if (abs(taste_abs_min) > abs(taste)) taste_abs_min = taste;
	}

	cout << sum - taste_abs_min << endl;
}

int main()
{
    b_bite_eating();

    return 0;
}
