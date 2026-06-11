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
using namespace std;

typedef vector<int> Ivec;

int main() {
	int n, p;

	while (scanf("%d %d", &n, &p)) {
		if (n == 0)
			return 0;

		int turn = 0, wan = p;
		array<int, 50> mayer = {};
		while (1) {

			if (wan == 0) {
				wan = mayer[turn];
				mayer[turn] = 0;
			}
			else if (wan == 1 && mayer[turn]+1 == p) 
				break;
			else {
				wan--;
				mayer[turn]++;
			}
			turn++;
			turn -= ((int)(turn / n) * n);
		}
		printf("%d\n", turn);
	}

	return 0;
}