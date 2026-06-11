#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>
#include <iomanip>

using namespace std;



int main() {
	int k, a, b;
	cin >> k >> a >> b;

	if (k == 1 ||a%k==0||b%k==0) {
		cout << "OK" << endl;
		return 0;
	}

	if (a / k == b / k)cout << "NG" << endl;
	if (a / k != b / k)cout << "OK" << endl;

	return 0;
}