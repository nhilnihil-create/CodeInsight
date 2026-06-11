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
	ld l;
	cin >> l;
	l /= 3;
	printf("%Lf\n", l * l * l);

	return 0;
}
