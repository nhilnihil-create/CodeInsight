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
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	if (a1 + a2 + a3 >= 22) {
		cout << "bust" << endl;
	} else {
		cout << "win" << endl;
	}

	return 0;
}
