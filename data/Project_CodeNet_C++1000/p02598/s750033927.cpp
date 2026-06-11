#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
using namespace std;
const int maxn = 2e5 + 10;
int n, k, a[maxn];

int check(int x) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += (a[i] - 1) / x;
		if (cnt > k) return 0;
	}
	return 1;
}

int main()
{
	#ifdef DEBUG
	freopen("text.in", "r", stdin);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int L = 0, R = 1e9, mid;
	while (L + 1 < R) {
		mid = (L + R) >> 1;
		if (check(mid)) R = mid;
		else L = mid;
	}
	printf("%d\n", R);
	return 0;
}
