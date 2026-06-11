#include<cstdio>
using namespace std;

int main(void) {
	int N, X;
	scanf("%d %d", &N, &X);
	int L[110];
	int D = 0;
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &L[i]);
		D += L[i];
		if (D <= X) cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
