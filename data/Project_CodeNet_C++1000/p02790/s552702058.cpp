#include <assert.h>
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
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

string builds(int a, int b) {
	char c = b + '0';
	string ret = "";
	for (int i = 0; i < a; i++) {
		ret += c;
	}
	return ret;
}

int main() {
	int a, b;
	string s1, s2;
	cin >> a >> b;
	s1 = builds(a, b);
	s2 = builds(b, a);
	if (s1 < s2) {
		cout << s1 << endl;
	} else {
		cout << s2 << endl;
	}

	return 0;
}
