#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;

struct node {
	int a, b, last;
	bool operator<(const node &rhs) {
		if (last != rhs.last) return last > rhs.last;
		return b > rhs.b;
	}
} job[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &job[i].a, &job[i].b);
		job[i].last = m - job[i].a;
	}
	sort(job, job + n);
	priority_queue<int> pq;
	int ans = 0;
	for (int i = m - 1, j = 0; i >= 0; i--) {
		while (j < n && job[j].last >= i) {
			pq.push(job[j].b);
			j++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	printf("%d\n", ans);
	return 0;
}
