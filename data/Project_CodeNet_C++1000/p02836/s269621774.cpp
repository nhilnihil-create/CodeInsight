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
	int l = 0, r = s.length() - 1;
	int ret = 0;
	while (l < r) {
		if (s[l] != s[r]) {
			ret++;
		}
		l++;
		r--;
	}
	cout << ret << endl;
	return 0;
}
