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
	int s, w;
	cin >> s >> w;
	if (w >= s) {
		cout << "unsafe";
	} else {
		cout << "safe";
	}
	return 0;
}
