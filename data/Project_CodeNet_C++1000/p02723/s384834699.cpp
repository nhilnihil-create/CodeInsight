#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
	char str[7];

	bool flag = false;
	
	cin >> str;

	if (str[2] == str[3]) {
		if (str[4] == str[5]) {
			flag = true;
		}
	}

	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}