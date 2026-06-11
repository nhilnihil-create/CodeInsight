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

typedef long double ld;
typedef long long ll;

using namespace std;

int main() {
	string s, t, u;
	int a, b;
	cin >> s >> t;
	cin >> a >> b;
	cin >> u;
	if (s == u) {
		a--;
	} else {
		b--;
	}
	cout << a << " " << b << endl;
	return 0;
}
