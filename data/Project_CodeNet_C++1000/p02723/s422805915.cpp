#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>

typedef long double ld;
typedef long long ll;

using namespace std;

int main() {
	string s;
	cin >> s;
	if (s[2] == s[3] && s[4] == s[5]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
