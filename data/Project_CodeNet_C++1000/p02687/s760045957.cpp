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
	string s;
	cin >> s;

	if (s == "ABC")cout << "ARC" << endl;

	if (s == "ARC")cout << "ABC" << endl;

	return 0;
}