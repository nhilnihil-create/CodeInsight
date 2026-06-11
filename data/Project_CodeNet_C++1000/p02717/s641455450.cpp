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

void swap(int & a, int & b) {
	int t = a;
	a = b;
	b = t;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	swap(a, b);
	swap(a, c);
	cout << a << " " << b << " " << c << endl;

	return 0;
}
