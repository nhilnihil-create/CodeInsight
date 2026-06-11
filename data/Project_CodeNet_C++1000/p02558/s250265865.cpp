#include <cstdio>
#include <atcoder/dsu>

int main()
{
	int N, Q;
	scanf("%d%d", &N, &Q);
	atcoder::dsu d(N);
	for (int i = 0; i < Q; ++i) {
		int t, u, v;
		scanf("%d%d%d", &t, &u, &v);
		if (t == 0) {
			d.merge(u, v);
		} else {
			printf("%d\n", d.same(u, v));
		}
	}
	return 0;
}
