#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_greedy_takahashi(void) {
	long long a, b, k;
	cin >> a >> b >> k;

	if (k >= a) {
		k -= a;
		a = 0;
	}
	else {
		a -= k;
		k = 0;
	}

	if (k > 0) {
		b -= k;
		if (b < 0) b = 0;
	}

	cout << a << " " << b << endl;
}

int main()
{
    b_greedy_takahashi();

    return 0;
}
