#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h> 
#include <stack>
#include <bitset>
#include <map>
#include <cmath>
#include <climits>
#include <queue>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
	int A, B, C, D, i = 1;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	while (true) {
		// Aoki
		if (i % 2 == 0) A -= D;
		// Takahashi
		else C -= B;

		i++;

		if (A <= 0) {
			printf("No\n");
			break;
		}
		else if (C <= 0) {
			printf("Yes\n");
			break;
		}
	}
}