#include <stdio.h>
#include <set>
using namespace std;

int N, P[100100], R[100100];

int main()
{
	scanf ("%d", &N);
	for (int i = 1; i <= N; i++) scanf ("%d", &P[i]), R[P[i]] = i;

	set<int> pos = { 0, N + 1, R[N] };
	long long ans = 0;
	for (int i = N - 1; i >= 1; i--){
		int r = R[i];
		auto I = pos.lower_bound(r);
		auto J = I; J--;
		long long intv = 0;
		if (*J != 0){
			auto K = J; K--;
			intv += 1ll * (*J - *K) * (*I - r);
		}
		if (*I != N + 1){
			auto K = I; K++;
			intv += 1ll * (*K - *I) * (r - *J);
		}
		ans += intv * i;
		pos.insert(r);
	}

	printf ("%lld\n", ans);

	return 0;
}