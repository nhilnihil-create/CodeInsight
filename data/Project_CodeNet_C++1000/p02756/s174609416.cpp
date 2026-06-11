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
#include <deque>

typedef long double ld;
typedef long long ll;

using namespace std;

deque<char> d;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		d.push_back(s[i]);
	}
	int q;
	cin >> q;
	int flag = 0;
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			flag = 1 - flag;
			continue;
		}
		cin >> t;
		t--;
		char c;
		cin >> c;
		if (flag ^ t) {
			d.push_back(c);
		} else {
			d.push_front(c);
		}
	}
	string ret;
	while (!d.empty()) {
		ret += d.front();
		d.pop_front();
	}
	if (flag) {
		reverse(ret.begin(), ret.end());
	}
	cout << ret << endl;

	return 0;
}
