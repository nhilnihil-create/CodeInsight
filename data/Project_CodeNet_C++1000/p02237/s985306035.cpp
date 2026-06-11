#include <cstdio>
using namespace std;

#define MAX 100
int main() {
	int n = 0;
	scanf("%d", &n);
	int M[MAX][MAX] = { 0 };
	for (int i = 0; i < n; i++) {
		int u, k;
		scanf("%d%d", &u, &k);
		u--;
		for (int j = 0; j < k; j++) {
			int v = 0;
			scanf("%d", &v);
			v--;
			M[u][v] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j) printf(" ");
			printf("%d",M[i][j]);
		}
		printf("\n");
	}
	return 0;

}