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
	int ans = 0;
	cin >> s;
	set<string> st;
	string co = "";
	string co1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	for (int i = 0; i < s.size(); i++) {
		co += s[i];
		if (co1 == co) {
			continue;
		}
		else {
			co1 = co;
			co = "";
			ans++;
			continue;
		}
	}
	cout << ans << endl;
}