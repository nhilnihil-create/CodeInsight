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
	string s, t;
	int n;
	cin >> n;
	cin >> s >> t;
	for (int i = 0; i < s.length(); i++) {
		cout << s[i] << t[i];
	}
	cout << endl;

	return 0;
}
