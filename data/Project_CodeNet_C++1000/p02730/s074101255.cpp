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

bool pal(string s) {
	bool ret = true;
	
	int i = 0, j = (int)s.length() - 1;
	while (i <= j) {
		if (s[i] != s[j]) {
			ret = false;
		}
		i++;
		j--;
	}

	return ret;
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	if (pal(s) && pal(s.substr(0, (n - 1)/2)) && pal(s.substr((n + 1)/2, (n - 1)/2))) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}
