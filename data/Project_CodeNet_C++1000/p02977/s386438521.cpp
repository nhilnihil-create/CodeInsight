#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int mod = 1000000007;
typedef long long LL;
int n, m, u[N], v[N], du[N], a[N];
set<int> G[N];
set<pair<int, int>> s;
pair<int, int> ans[N];
int main() {
#ifdef TEST
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	int fst = 1;
	while (fst < n) fst <<= 1;
	if (fst == n) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	printf("1 2\n2 3\n3 %d\n", n + 1);
	printf("%d 1\n%d %d\n", n + 3, n + 3, n + 2);
	if (n & 1) {
		for (int i = 4; i <= n; i += 2) {
			printf("%d %d\n", n + i, n + i + 1);
			printf("%d %d\n", n + i + 1, 3);
			printf("%d %d\n", i, 2);
			printf("%d %d\n", i + 1, i);
		}
	} else {
		int t = n;
		fst = fst >> 1;
		vector<int> q;
		while (t) {
			if (t >= fst) {
				q.push_back(fst);
				t -= fst;
			}
			fst >>= 1;
		}
		reverse(q.begin(), q.end());
		int head = q[0] == 2;
		for (int i = 4; i < n; i += 2) {
			if (head < q.size() && q[head] == i) {
				int pre = head == 0 ? 2 : q[head - 1];
				printf("%d %d\n", pre, i);
				printf("%d %d\n", i, i + 1);
				printf("%d %d\n", pre + 1, n + i + 1);
				printf("%d %d\n", n + i + 1, n + i);
				head++;
			} else {
				printf("%d %d\n", n + i, n + i + 1);
				printf("%d %d\n", n + i + 1, 3);
				printf("%d %d\n", i, 2);
				printf("%d %d\n", i + 1, i);
			}
		}
		printf("%d %d\n", q[0], n);
		printf("%d %d\n", q[head - 1], n + n);
	}
	return 0;
}