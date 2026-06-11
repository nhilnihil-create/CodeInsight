#include <cstdio>

int main() {
	int N; scanf("%d", &N);
	long long numOfNodes = 0;
	for (int i = 1; i <= N; i++) {
		numOfNodes += ((long long)i) * (N - i + 1);
	}
	long long numOfEdges = 0;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b) {
			int c = a;
			a = b;
			b = c;
		}
		numOfEdges += ((long long)a) * (N - b + 1);
	}
	printf("%lld", numOfNodes - numOfEdges);
	return 0;
}