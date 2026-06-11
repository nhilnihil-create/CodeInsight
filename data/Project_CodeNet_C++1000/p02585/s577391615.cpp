#include <cstdio>
#include <algorithm>
using namespace std;

//#define scanf scanf_s
#define LL long long
#define maxn 5010

LL p[maxn], c[maxn], t[maxn], d[maxn], mid[maxn];

int main() {
	int n, k, i, now, cnt;
	LL mx = -1000000000, val;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%lld", &p[i]);
	for (i = 1; i <= n; i++)
		scanf("%lld", &c[i]);
	for (i = 1; i <= n; i++) {
		now = p[i];
		d[i] = c[now];
		t[i] = 1;
		mid[i] = -1000000000;
		mid[i] = max(d[i], mid[i]);
		while (1) {
			if (now == i)break;
			t[i]++;
			now = p[now];
			d[i] += c[now];
			mid[i] = max(d[i], mid[i]);
		}
	}
	for (i = 1; i <= n; i++) {
		if (k / t[i] > 0) {
			mx = max(mx, mid[i]);
			if (k % t[i] == 0) {
				mx = max(mx, (k / t[i] - 1) * d[i] + mid[i]);
				continue; 
			}
		}
		val = k / t[i] * d[i];
		now = p[i];
		val += c[now];
		mx = max(mx, val);
		cnt = 1;
		while (1) {
			if (k % t[i] == cnt)break;
			cnt++;
			now = p[now]; val += c[now];
			mx = max(mx, val);
		}
	}
	printf("%lld\n", mx);
	return 0;
}