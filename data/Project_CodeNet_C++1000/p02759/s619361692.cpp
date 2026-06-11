#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	if (N % 2 != 0) {
		N++;
	}
	printf("%d\n", N / 2);
}