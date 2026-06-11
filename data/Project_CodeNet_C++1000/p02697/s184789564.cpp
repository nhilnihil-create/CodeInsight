#include <stdio.h>

int main()
{
	int N, M; scanf ("%d %d", &N, &M);
	int L = (N - 1) / 2;

	int u = (L + 1) / 2, v = L / 2;
	
	for (int s = u, e = u + 1; s >= 1; s--, e++){
		printf ("%d %d\n", s, e);
		if (--M == 0) return 0;
	}

	for (int s = 2 * u + v, e = s + 2; s > 2 * u; s--, e++){
		printf ("%d %d\n", s, e);
		if (--M == 0) return 0;
	}

	return 0;
}