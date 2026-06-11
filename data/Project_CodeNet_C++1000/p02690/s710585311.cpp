#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int MIN = -200;
const int MAX = 200;

long by_5(int a, int b) {
	return powl(a, 5) - powl(b, 5);
}

int main() {
	long x;
	cin >> x;

	for (int i = MIN;i <= MAX;i++) {
		for (int j = MIN;j <= MAX;j++) {
			if (x == by_5(i, j)) {
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}

	return 0;
}