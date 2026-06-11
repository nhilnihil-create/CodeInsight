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
	int a, b;
	cin >> a >> b;
	if (a >= 1 && a <= 9 && b >= 1 && b <= 9) {
		cout << a * b << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}
