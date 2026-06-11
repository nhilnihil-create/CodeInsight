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
#include <set>
#include <stack>

using namespace std;
int arr[123456 * 2 + 1] = {};
void Eratosthenes(int N) {
	for (int i = 0; i < N; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i < sqrt(N); i++) {
		if (arr[i]) {
			for (int j = 0; i * (j + 2) < N; j++) {
				arr[i *(j + 2)] = 0;
			}
		}
	}
	arr[0] = 0;
	arr[1] = 0;
}
int main() {
	int n;
	Eratosthenes(123456*2+1);
	while (scanf("%d", &n)) {
		if (n == 0)
			return 0;
		int cou = 0;
		for (int i = n+1; n * 2 >= i; i++) {
			if (arr[i]) {
				cou++;
			}
		}
		printf("%d\n", cou);
	}
	
	return 0;
}