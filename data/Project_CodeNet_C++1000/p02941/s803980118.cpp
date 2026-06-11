#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int a[200000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int b[200000];
	priority_queue<pair<int, int> > pq;
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		if (a[i] > b[i]) {
			puts("-1");
			return 0;
		}
		if (a[i] == b[i]) continue;	
		pq.push(make_pair(b[i], i));
	}
	
	long long cnt = 0;
	while (!pq.empty()) {
		int id = pq.top().second;
		pq.pop();
		int s = (id == 0) ? n-1 : id-1;
		int t = (id == n-1) ? 0 : id+1;
		if ((b[id]-a[id])%(b[s]+b[t]) == 0) {
			cnt += (b[id]-a[id])/(b[s]+b[t]);
			b[id] = a[id];
			continue;
		} else if (b[id] <= b[s]+b[t]) {
			puts("-1");
			return 0;
		} else {
			cnt += b[id]/(b[s]+b[t]);
			b[id] %= b[s]+b[t];
			pq.push(make_pair(b[id], id));
		}
	}
	
	printf("%lld\n", cnt);
	
	return 0;
}
