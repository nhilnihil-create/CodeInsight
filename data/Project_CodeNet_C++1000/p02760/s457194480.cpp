#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	int a[3][3];
	for (int i = 0;i < 3;i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	int n;
	cin >> n;
	vector<int> b(n);

	for (int i = 0;i < n;i++) {
		cin >> b[i];
	}

	for (int i = 0;i < n;i++) {		
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 3;k++) {
				if (b[i] == a[j][k]) {
					a[j][k] = 0;
				}
			}
		}
	}

	for (int i = 0;i < 3;i++) {
		if (a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	for (int i = 0;i < 3;i++) {
		if (a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0) {
		cout << "Yes" << endl;
		return 0;
	}

	if (a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0) {
		cout << "Yes" << endl;
		return 0;
	}

	cout << "No" << endl;

	return 0;
}
