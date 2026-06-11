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
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		s[i] = (s[i] - 'A' + n) % 26 + 'A';
	}
	cout << s << endl;
	return 0;
}
