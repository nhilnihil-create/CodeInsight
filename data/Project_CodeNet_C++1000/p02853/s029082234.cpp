#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int x, y, g[1000] = {0};

int main() {

	g[1] = 300000;
	g[2] = 200000;
	g[3] = 100000;

	scanf("%d %d", &x, &y);

	if (x > y) {
		swap(x, y);
	}

	int res = g[x] + g[y];

	if (x == 1 && y == 1) {
		res += 400000;
	}

	printf("%d\n", res);

	return 0;

}