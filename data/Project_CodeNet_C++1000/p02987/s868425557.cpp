#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
vector<int> a, b;
int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (s[0] == s[1] && s[2] == s[3] && s[0] != s[2]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
