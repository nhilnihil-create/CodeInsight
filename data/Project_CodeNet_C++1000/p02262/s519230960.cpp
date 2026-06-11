#include<stdio.h>
#include<string.h>

struct NUM {
	int cnt;
	int m;
	int G[100];
};

int InsertionSort(int A[], int n, int g) {
	int i, v, j, cnt = 0;
	for (i = g; i < n; i++) {
		v = A[i]; j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j]; j = j - g; cnt++;
		}
		A[j + g] = v;
	}
	return cnt;
}

int dev3(int N) {
	int i = 1;
	while (i < N) {
		if (3 * i + 1 > N)break;
		i = 3 * i + 1;
	}
	return i;
}

struct NUM ShellSort(int A[], int n) {
	struct NUM num;
	int cnt = 0;
	int m = 0;
	int G[100];
	for (int i = dev3(n); i > 0; i = (i - 1) / 3) {
		G[m] = i;
		m++;
	}
	for (int i = 0; i < m; i++) {
		cnt += InsertionSort(A, n, G[i]);
	}
	num.cnt = cnt; num.m = m; for (int i = 0; i < m; i++) num.G[i] = G[i];
	return num;
}


int main() {
	int N, A[1000000];
	struct NUM num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	num = ShellSort(A, N);
	printf("%d\n", num.m);
	for (int i = 0; i < num.m; i++) {
		if (i == num.m - 1) {
			printf("%d\n", num.G[i]);
			break;
		}
		printf("%d ", num.G[i]);
	}
	printf("%d\n", num.cnt);
	for (int i = 0; i < N; i++) {
		printf("%d\n", A[i]);
	}
	return 0;
}
