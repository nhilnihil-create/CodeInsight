#include <bits/stdc++.h>
using namespace std;

int lobit(int x) {
	int res = 0;
	for (; !(x % 2); x /= 2)
		res++;
	return res;
}

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++)
			printf("%d ", lobit(i ^ j) + 1);
		puts("");
	}
	
	return 0;
}