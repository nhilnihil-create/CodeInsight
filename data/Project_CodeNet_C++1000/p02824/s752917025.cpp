#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int maxn = 100000;

int n, m, v, p;
int a[maxn];
int64_t pref[maxn + 1];

signed main () {
    scanf("%d %d %d %d", &n, &m, &v, &p);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; ++i)
		pref[i + 1] = pref[i] + a[i];
	ans = p;
	for (int i = p; i < n; ++i) {
		if (a[i] + m < a[p - 1]) 
            break;
		int64_t cur = v - (n - (i - p + 1));
		if (cur <= 0) {
			++ans;
			continue;
		}
		if (cur * m <= (i - p + 1) * (a[i] + m) - (pref[i] - pref[p - 1]))
			++ans;
	}
	printf("%d \n", ans);
}
