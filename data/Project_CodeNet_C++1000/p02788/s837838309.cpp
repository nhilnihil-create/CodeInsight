#include <stdio.h>
#include <algorithm>
using namespace std;

int N, D, A; pair<int, int> M[200200];
int cnt = 1, coord[400400];
long long sum[400400];

void push(int x, long long p)
{
	x = lower_bound(coord + 1, coord + cnt, x) - coord;
	while (x < cnt){
		sum[x] += p;
		x += x & (-x);
	}
}

long long pop(int x)
{
	long long r = 0;
	x = lower_bound(coord + 1, coord + cnt, x) - coord;
	while (x){
		r += sum[x];
		x -= x & (-x);
	}
	return r;
}

int main()
{
	scanf ("%d %d %d", &N, &D, &A);
	for (int i = 0, x, h; i < N; i++){
		scanf ("%d %d", &x, &h); x -= D;
		M[i] = { x, h };
		coord[cnt++] = x;
		coord[cnt++] = x + 2 * D + 1;
	}

	sort(coord + 1, coord + cnt);
	sort(M, M + N);

	long long drop = 0;
	for (int i = 0; i < N; i++){
		long long nh = M[i].second - pop(M[i].first);
		if (nh > 0){
			long long d = (nh + A - 1) / A;
			push(M[i].first, d * A);
			push(M[i].first + 2 * D + 1, -d * A);
			drop += d;
		}
	}

	printf ("%lld\n", drop);

	return 0;
}