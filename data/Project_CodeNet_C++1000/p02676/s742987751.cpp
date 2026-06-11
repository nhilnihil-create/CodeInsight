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

using namespace std;

int main() {
	string s;
	int k;

	cin >> k;

	cin >> s;

	if (s.size() > k) {
		s = s.substr(0,k) + "...";
		cout << s << endl;
	}

	if (s.size() <= k) {
		cout << s << endl;
	}
	return 0;
}