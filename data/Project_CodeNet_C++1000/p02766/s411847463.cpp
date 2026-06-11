#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_digits(void) {
	long long n;
	int k;

	cin >> n >> k;
	int keta = 0;
	while (n > 0) {
		n /= k;
		keta++;
	}
	cout << keta << endl;
}
int main()
{
    b_digits();

    return 0;
}

