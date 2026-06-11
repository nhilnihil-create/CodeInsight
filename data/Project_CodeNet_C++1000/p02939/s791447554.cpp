#include <iostream>
#include <string>
#include <algorithm>
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
int main() {
	string s;
	cin >> s;
	int n = s.size();
	string s1 = "";
	int now = 0;
	int co = 0;
	for (int i = 1; i <= n; i++) {
		if (s.substr(now, i - now) != s1) {
			s1 = s.substr(now, i - now);
			now = i;
			co++;
		}
	}
	cout << co << endl;
	return 0;
}
