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
	int a[3];
	cin >> a[0] >> a[1] >> a[2];

	if (a[0] + a[1] + a[2] >= 22) {
		cout << "bust" << endl;
	}
	else {
		cout << "win" << endl;
	}

	return 0;
}