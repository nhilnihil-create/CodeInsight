#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_easy_linear_programming(void) {
	long long a, b, c, k;
	cin >> a >> b >> c >> k;

	long long sum = 0;

	if (k >= a) {
		sum = a;
		k -= a;
	}
	else {
		sum += k;
		cout << sum << endl;
		return;
	}
	if (k >= b) {
		k -= b;
	}
	else {
		cout << sum << endl;
		return;
	}

	sum += (-1) * k;

	cout << sum << endl;


}
int main()
{
    b_easy_linear_programming();

    return 0;
}
