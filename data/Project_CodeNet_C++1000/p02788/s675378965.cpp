#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int N, D, A;
pair<int, int> M[200200];

int main()
{
	scanf ("%d %d %d", &N, &D, &A);
	for (int i = 0; i < N; i++){
		int x, h; scanf ("%d %d", &x, &h);
		x -= D;
		M[i] = { x,h };
	}
	sort(M, M + N);

	long long drops = 0, have = 0;
	queue<pair<int, long long> > Q;
	for (int i = 0; i < N; i++){
		while (!Q.empty() && Q.front().first < M[i].first){
			have -= Q.front().second;
			Q.pop();
		}
		
		long long nh = M[i].second - have * A;
		if (nh > 0){
			long long d = (nh + A - 1) / A;
			Q.push({ M[i].first + 2 * D, d });
			drops += d;  have += d;
		}
	}

	printf ("%lld\n", drops);

	return 0;
}
