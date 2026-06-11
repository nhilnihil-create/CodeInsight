#include <cstdio>
#include <algorithm>
using namespace std;

const int non = 0x0fffffff;
int N, M, D[1<<12], P[1<<12];

int main()
{
	scanf ("%d %d", &N, &M);

	for (int i = 1; i < (1 << N); i++) D[i] = P[i] = non;
	while (M--){
		int a, b, c = 0;
		scanf ("%d %d", &a, &b); while (b--){
			int x;
			scanf ("%d", &x);
			c |= 1 << (x - 1);
		}

		for (int i = 0; i < (1 << N); i++) P[i | c] = min(P[i | c], D[i] + a);
		for (int i = 0; i < (1 << N); i++) D[i] = P[i];
	}

	int ans = D[(1 << N) - 1];
	if (ans == non) ans = -1;
	printf ("%d\n", ans);
	return 0;
}