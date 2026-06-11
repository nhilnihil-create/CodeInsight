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
	int n, m, A, B;
	scanf("%d %d", &n, &m);
	vector<int> height(n);
	vector<bool> ok(n, true);
	rep(i, n) scanf("%d", &height[i]);

	rep(i, m) {
		scanf("%d %d", &A, &B);
		A--; B--;
		if (height[A] <= height[B]) ok[A] = false;
		if (height[B] <= height[A]) ok[B] = false;
	}

	A = 0;
	rep(i, n) if (ok[i]) A++;

	printf("%d\n", A);
}