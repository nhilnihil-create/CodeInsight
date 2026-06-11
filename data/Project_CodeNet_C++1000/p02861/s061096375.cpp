#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	int n;

	scanf("%d", &n);

	pair<int, int> v[10];

	for (int i = 0; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[i] = {x, y};
	}

	sort(v, v+n);

	double ansV = 0.00, ansQ = 0.00;

	do {
		double dist = 0.00;
		for (int i = 0; i < n-1; i++){
			dist += sqrt( (v[i].f - v[i + 1].f) * (v[i].f - v[i + 1].f) + 
					(v[i].s - v[i + 1].s) * (v[i].s - v[i + 1].s) );
		}
		ansV += dist;
		ansQ += 1;
	} while (next_permutation(v, v+n));

	printf("%lf\n", ansV / ansQ);

	return 0;
}