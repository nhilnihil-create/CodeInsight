#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int maxn = 1e5 + 10;
int n,a[maxn];
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	if (n == 2) {
		printf("%d\n%d %d\n",a[2] - a[1],a[2],a[1]);
	} else if (a[n] <= 0) {
		int sum = a[n];
		for (int i = 1; i < n; i++)
			sum -= a[i];
		printf("%d\n",sum);
		int cur = a[n];
		for (int i = n - 1; i >= 1; i--) {
			printf("%d %d\n",cur,a[i]);
			cur -= a[i];
		}
	} else if (a[1] >= 0) {
		int sum = -a[1];
		for (int i = 2; i <= n; i++)
			sum += a[i];
		printf("%d\n",sum);
		int cur = a[1];
		for (int i = 3; i <= n; i++) {
			printf("%d %d\n",cur,a[i]);
			cur -= a[i];
		}
		printf("%d %d\n",a[2],cur);
	} else {
		int p = 1;
		for (int i = 1; i <= n; i++)
			if (a[i] >= 0) {
				p = i;
				break;
			}
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += abs(a[i]);
		printf("%d\n",sum);
		int cur = a[1];
		for (int i = p + 1; i <= n; i++) {
			printf("%d %d\n",cur,a[i]);
			cur -= a[i];
		}
		printf("%d %d\n",a[p],cur);
		cur = a[p] - cur;
		for (int i = 2; i < p; i++) {
			printf("%d %d\n",cur,a[i]);
			cur -= a[i];
		}
	}
	return 0;
}