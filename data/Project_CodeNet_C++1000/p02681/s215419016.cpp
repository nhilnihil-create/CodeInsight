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
	string s,t;

	cin >> s >> t;

	if (t.substr(0,s.size()) == s)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}