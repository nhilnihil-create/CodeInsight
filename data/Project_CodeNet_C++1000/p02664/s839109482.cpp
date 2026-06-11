#include <bit>
#include <bitset>
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

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			s[i] = 'D';
		}
	}
	cout << s << endl;
	return 0;
}
