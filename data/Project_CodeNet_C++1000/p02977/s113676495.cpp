#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > edge;

int main() {
#ifdef LOACL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N;
	scanf("%d", &N);
	int t = 1;
	while(t <= N) {
		if(t == N) {
			puts("No");
			return 0;
		}
		t <<= 1;
	}
	for(int i = 1; i < 3; i++) {
		edge.push_back(make_pair(i, i + 1));
		edge.push_back(make_pair(i + N, i + N + 1));
	}
	edge.push_back(make_pair(3, N + 1));
	for(int i = 4; i + 1 <= N; i += 2) {
		edge.push_back(make_pair(1, i));
		edge.push_back(make_pair(i, i + 1));
		edge.push_back(make_pair(1, N + i + 1));
		edge.push_back(make_pair(N + i, N + i + 1));
	}
	if(N % 2 == 0) {
		for(int i = 2; i < N; i++) {
			int a = N ^ i ^ 1, b = i;
			if(1 <= a && a < N) {
				if(a == b) continue;
				if(a & 1) edge.push_back(make_pair(N + a, N));
				else edge.push_back(make_pair(a, N));
				if(b & 1) edge.push_back(make_pair(N + b, 2 * N));
				else edge.push_back(make_pair(b, 2 * N));
				break;
			}
		}
	}
	puts("Yes");
	for(int i = 0; i < (int)edge.size(); i++)
		printf("%d %d\n", edge[i].first, edge[i].second);
	return 0;
}