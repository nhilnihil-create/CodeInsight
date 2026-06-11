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
	int h1, m1, h2, m2, k;
	cin >> h1 >> m1 >> h2 >> m2 >> k;
	int diff = (h2 - h1) * 60 + m2 - m1;
	cout << diff - k << endl;

	return 0;
}
