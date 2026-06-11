#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <stack>

using namespace std;

#define Getsign(n) ((n > 0) - (n < 0))
#define QWERTYR(c) (c == 'y' || c == 'u' || (c >= 'h' && c <= 'p') ?	true : false)
typedef vector<int> Ivec;
typedef pair<int, int> pii; // (cst, to)

int main() {
	int x, y, s;

	while (scanf("%d %d %d", &x, &y, &s)) {
		if (x == 0) {
			return 0;
		}

		int Max = 0;

		for (int i = 1; s >= i; i++) {
			for (int j = i; s >= j; j++) {
				if (s == (int) ((100+x) * i / 100) + (int) ((100 + x) * j / 100)) {
					Max = max(Max, (int) ((100 + y) * i / 100) + (int) ((100 + y) * j / 100));
				}
			}
		}
		printf("%d\n", Max);
	}


	return 0;
}