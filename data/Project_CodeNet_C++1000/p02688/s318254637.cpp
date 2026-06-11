//#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int n, k, d, cnt = 0;
	cin >> n >> k;
	int a[100];
	for (int i = 0; i < 100; i++) {
		a[i] = 0;
	}

	for (int i = 0; i < k; i++) {
		cin >> d;
		for (int j = 0; j < d; j++) {
			int x;
			cin >> x;
			if (a[x - 1] != 1) {
				a[x - 1] = 1;
				cnt++;
			}
		}
	}
	cout << n - cnt << endl;
	return 0;
}