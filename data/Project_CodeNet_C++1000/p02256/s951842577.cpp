#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {

	int x, y;
	scanf("%d %d", &x, &y);

	if (x < y)
		swap(x, y);

	while (y > 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	cout << x << endl;

	return 0;
}