#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

int main()
{
	string str;
	cin >> str;
	bool ans = true;
	for (int i = 1; i <= str.size(); i++) {
		if (i % 2 == 0 && str[i - 1] == 'R') {
			ans = false;
		}
		if (i % 2 == 1 && str[i - 1] == 'L') {
			ans = false;
		}
	}
	if (ans == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}