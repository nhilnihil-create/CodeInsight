#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;
int main() {
	vector<int>c(26);
	while (true) {
		string x;
		getline(cin, x);
		if (x == "")break;
		for (int i = 0; i < x.size(); i++) {
			if ('a' <= x[i] && x[i] <= 'z')c[x[i] - 'a']++;
			if ('A' <= x[i] && x[i] <= 'Z')c[x[i] - 'A']++;
		}
	}
	for (int i = 'a'; i <= 'z'; i++) {
		cout << (char)i << " : " << c[i - 'a'] << endl;
	}
	return 0;
}
