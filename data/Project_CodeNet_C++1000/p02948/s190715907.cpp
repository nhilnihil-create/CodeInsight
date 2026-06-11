#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> pq;
pair<int, int> a[111111];

int main(void)
{
	int n, m, i, ans = 0;

	scanf("%d %d" ,&n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d %d" ,&a[i].first, &a[i].second);

	sort(a + 1, a + n + 1);

	int take = 1;
	for (i = 0; i < m; i++)
	{
		while (a[take].first == i + 1)
		{
			pq.push(a[take].second);
			++take;
			if (take > n)
				break;
		}

		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}

	printf("%d" ,ans);
	return 0;
}