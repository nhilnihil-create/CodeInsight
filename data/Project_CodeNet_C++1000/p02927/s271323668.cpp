#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int m, d, res = 0;

int main() {

	scanf("%d %d", &m, &d);

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= d; j++) {
			int x = j / 10;
			int y = j % 10;
			if (x >= 2 && y >= 2 && x * y == i) res++;
		}
	}

	printf("%d\n", res);

	return 0;

}