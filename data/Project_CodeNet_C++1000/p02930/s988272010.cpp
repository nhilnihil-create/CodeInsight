#include <bits/stdc++.h>
using namespace std;
int n;
int lowbit(int x) {
	for (int i = 0;; i ++) if (x >> i & 1) return i + 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i ++) {
		for (int j = i + 1; j < n; j ++) {
			printf("%d ", lowbit(i ^ j));
		}
		printf("\n");
	}
}