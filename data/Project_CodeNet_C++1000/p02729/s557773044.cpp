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

int ch(int n) {
	return (n * (n - 1)) / 2;
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << ch(n) + ch(m);
	return 0;
}
