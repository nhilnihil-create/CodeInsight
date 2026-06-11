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
	int n, k;
	cin >> n >> k;
	int ret = 0;
	while (n) {
		ret++;
		n /= k;
	}
	cout << ret << endl;
	return 0;
}
