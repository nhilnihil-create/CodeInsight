#include <stdio.h>
#include <set>
using namespace std;

int N, P[100100], R[100100];

int main()
{
	scanf ("%d", &N);
	for (int i = 1; i <= N; i++) scanf ("%d", &P[i]), R[P[i]] = i;

	multiset<int> pos = { 0, 0, N + 1, N + 1, R[N] };
	long long ans = 0;
	for (int i = N - 1; i >= 1; i--){
		int r = R[i];
		auto I = pos.lower_bound(r);
		auto J = I; J--;
		auto K = I; K++;
		auto L = J; L--;
		ans += (1ll * (*J - *L) * (*I - r) + 1ll * (*K - *I) * (r - *J)) * i;
		pos.insert(r);
	}

	printf ("%lld\n", ans);

	return 0;
}
