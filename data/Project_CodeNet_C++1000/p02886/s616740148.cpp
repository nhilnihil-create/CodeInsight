#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_takoyaki_festival2019(void) {
	int n;
	cin >> n;
	vector<int> d(n);
	int d_sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		d_sum += d[i];
	}

	int recovery_val = 0;
	for (int i = 0; i < n - 1; i++) {
		d_sum -= d[i];
		recovery_val += (d_sum * d[i]);
	}

	cout << recovery_val << endl;
}

int main()
{
    b_takoyaki_festival2019();

    return 0;
}