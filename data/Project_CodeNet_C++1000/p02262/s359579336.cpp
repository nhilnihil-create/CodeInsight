#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 1000001;
int A[MAX_N];
int N;
int cnt = 0;
vector<int> G;

void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
}

void show(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\n", *(a + i));
	}
}

void insertionSort(int *a, int n, int g) {
	for (int i = g; i < n; i++) {
		int v = a[i];
		int j = i - g;
		while (j >= 0 && a[j] > v) {
			a[j + g] = a[j];
			j -= g;
			cnt++;
		}
		a[j + g] = v;
	}
}

void shellSort(int *a, int n) {
	int h = 1;
	while (h <= n) {
		G.push_back(h);
		h = 3 * h + 1;
	}
	for (int i = G.size() - 1; i >= 0; i--) {
		insertionSort(a, n, G[i]);
	}
	printf("%d\n", G.size());
	for (int i = G.size() - 1; i >= 0; i--) {
		printf("%d", G[i]);
		if (i) {
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n", cnt);
	show(A, N);
}

void solve() {
	input();
	shellSort(A, N);
}

int main() {
	solve();
}