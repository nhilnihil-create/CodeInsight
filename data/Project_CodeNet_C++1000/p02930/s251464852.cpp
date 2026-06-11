#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			printf("%d ", __builtin_ctz(i ^ j) + 1);
		}
		printf("\n");
	}
	return 0;
}
