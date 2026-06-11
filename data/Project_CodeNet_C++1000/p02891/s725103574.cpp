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
	long long k, co1 = 0;
	long long ans = 0;
	long long o = 0, t = 0;
	cin >> s >> k;
	string s1 = s + s;
	for (int c = 1; c < s.size(); c++) {
		if (s[c] != s[c - 1]) {
			break;
		}
		else {
			co1++;
		}
	}
	if (co1 == s.size() - 1) {
		ans = s.size() * k / 2;
		cout << ans << endl;
		return 0;
	}
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			s[i] = '0';
			o++;
		}
	}
	for (int j = 1; j < s1.size(); j++) {
		if (s1[j] == s1[j - 1]) {
			s1[j] = '0';
			t++;
		}
	}
	t = t - o;
	ans = o + (k - 1) * t;
	cout << ans << endl;
	return 0;
}