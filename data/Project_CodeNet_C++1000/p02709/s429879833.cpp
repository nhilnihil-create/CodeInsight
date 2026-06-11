#include <stdio.h>
#include <algorithm>
using namespace std;

int N; pair<int, int> P[2020];
long long D[2020][2020];

int main()
{
	scanf ("%d", &N);
	for (int i = 0; i < N; i++) scanf ("%d", &P[i].first), P[i].second = i;
	sort(P, P + N);
	reverse(P, P + N);

	for (int i = 0; i < N; i++) for (int j = 0; i + j < N; j++){
		int k = i + j;
		D[i + 1][j] = max(D[i + 1][j], D[i][j] + 1ll * P[k].first * abs(P[k].second - i));
		D[i][j + 1] = max(D[i][j + 1], D[i][j] + 1ll * P[k].first * abs(P[k].second - (N - 1 - j)));
	}

	long long a = 0;
	for (int i = 0; i <= N; i++){
		a = max(a, D[i][N - i]);
	}
	printf ("%lld\n", a);

	return 0;
}
