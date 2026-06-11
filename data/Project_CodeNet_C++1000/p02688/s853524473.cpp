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
	int n, k, d, o;
	scanf("%d %d", &n, &k);
	vector<int> A(n, 0);
	rep(i, k) {
		scanf("%d", &d);
		rep(j, d) {
			scanf("%d", &o);
			A[o - 1]++;
		}
	}
	o = 0;
	rep(i, n) if (A[i] == 0) o++;
	printf("%d\n", o);
}