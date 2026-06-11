#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
inline int gcd(int x, int y) {
	int z = x % y;
	if (!z) return y;
	else gcd(y, z);
}
int main() {
	int x, y, z;
	cin >> x >> y;
	if (x < y) swap(x, y);
	cout << gcd(x,y) << endl;
	return 0;
}