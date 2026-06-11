#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#define MN 100005
#define INF 1000000007
using namespace std;
int n, m, v, p;
int a[MN];
bool cmp(const int i, const int j) {
	return i > j;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &v, &p);
	int i;
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n, cmp);
	int ans=p;
	if (v <= p) {
		for (i = p + 1; i <= n; i++) {
			if (a[p] <= a[i] + m) ans++;
			else break;
		}
	}
	else {
		v = v - p;
		long long votes;
		long long sum = a[p];
		for (i = p + 1; i <= n; i++) {
			if (a[p] > a[i] + m) break;
			if (n - i < v) {
				long long nv = v - (n - i);
				long long votes = nv * m;
				if (votes > (long long)(i - p)* (long long)(a[i] + m) - sum) break;
			}
			ans++;
			sum += a[i];
		}
	}
	printf("%d", ans);
	return 0;
}