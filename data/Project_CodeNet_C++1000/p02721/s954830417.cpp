#include <stdio.h>
using namespace std;

int N, K, C;
char S[200200]; int P[200200], Q[200200];

int main()
{
	scanf ("%d %d %d", &N, &K, &C);
	scanf ("%s", S);

	for (int i = 0, c = 0; i < N; i++) if (S[i] == 'o'){
		P[i] = ++c;
		i += C;
		if (c == K) break;
	}

	for (int i = N - 1, c = K; i >= 0; i--) if (S[i] == 'o'){
		Q[i] = c--;
		i -= C;
		if (c == 0) break;
	}

	for (int i = 0; i < N; i++) if (P[i] && P[i] == Q[i]) printf ("%d\n", i + 1);

	return 0;
}