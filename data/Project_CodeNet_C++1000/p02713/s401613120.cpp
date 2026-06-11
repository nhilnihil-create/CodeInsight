//#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

int main() {
	int k;
	cin >> k;
	int g, sum = 0;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			for (int h = 0; h <= k; h++) {
				for (g = min(min(i, j), min(j, h)); g >= 1; g--) {
					if (i % g == 0 && j % g == 0 && h % g == 0) {
						sum += g;
						break;
					}
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}