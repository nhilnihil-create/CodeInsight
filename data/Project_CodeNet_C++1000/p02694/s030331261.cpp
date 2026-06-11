#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	long long x;
	cin >> x;

	long long money = 100;
	if (x <= money) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1;i <= 3760;i++) {
		money = money + money / 100;
		if (x <= money) {
			cout << i << endl;
			return 0;
		}
	}
}