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
	int n;
	string s;
	int ret = 0;
	cin >> n >> s;
	for (int i = 0; i < n - 2; i++) {
		int ok = 1;
		for (int j = 0; j < 3; j++) {
			if (s[i + j] != 'A' + j) {
				ok = 0;
			}
		}
		ret += ok;
	}
	cout << ret << endl;

	return 0;
}
