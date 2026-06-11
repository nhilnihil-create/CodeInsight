#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int Maxn = 2e5;

int N, A[Maxn + 5], B[Maxn + 5];
priority_queue<pair<int, int> > q;

int main() {
//	freopen("hopeless.in", "r", stdin);
//	freopen("hopeless.out", "w", stdout);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)	
		scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &B[i]);
		if(A[i] != B[i])
			q.push(make_pair(B[i], i));
	}
	ll ans = 0;
	while(!q.empty()) {
		int pos = q.top().second;
		q.pop();
		int pre = (pos == 1 ? N : pos - 1), nxt = (pos == N ? 1 : pos + 1);
		if(B[pos] - A[pos] < B[pre] + B[nxt]) {
			puts("-1");
			return 0;
		}
		ans += (B[pos] - A[pos]) / (B[nxt] + B[pre]);
		B[pos] -= ((B[pos] - A[pos]) / (B[nxt] + B[pre])) * (B[nxt] + B[pre]);
		if(A[pos] != B[pos])
			q.push(make_pair(B[pos], pos));
	}
	printf("%lld\n", ans);
	return 0;
}