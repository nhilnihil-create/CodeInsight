#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N, M; pair<int, int> T[100100];

int main()
{
	scanf ("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf ("%d %d", &T[i].first, &T[i].second);
	sort(T, T + N);
	priority_queue<int> Q;
	long long ans = 0;
	for (int i = 1, j = 0; i <= M; i++){
		while (j < N && T[j].first <= i){
			Q.push(T[j].second);
			j++;
		}
		if (!Q.empty()){
			ans += Q.top();
			Q.pop();
		}
	}
	printf ("%lld\n", ans);

	return 0;
}