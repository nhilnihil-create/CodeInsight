#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

int C = 0;
int N = 0;
int R[10][10] = { 0 };
int M[10] = { 0 };

bool solve() {
	int sum = INT_MAX,ans = 0;
	for (int i = 0; i <= C; i++) {
		queue<int> q;
		q.push(i);
		M[i] = 0;
		while (!q.empty()) {
			for (int j = 0; j <= C; j++) {
				if (R[q.front()][j] != -1 && (M[j] == -1 || M[q.front()] + R[q.front()][j] < M[j])) {
					
					M[j] = R[q.front()][j] + M[q.front()];
					q.push(j);
				}
			}
			q.pop();
		}
		int s = 0;
		for (int j = 0; j <= C; j++)
			s += M[j];
		if (sum > s) {
			sum = s;
			ans = i;
		}
		memset(M, -1, sizeof(int) * 10);
	}
	printf("%d %d\n", ans,sum);
}

int main(void) {
	while(true){
		C = 0;
		memset(R, -1, sizeof(int) * 100);
		memset(M, -1, sizeof(int) * 10);
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int j = 0; j < N; j++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			R[a][b] = c;
			R[b][a] = c;
			C = max(C, max(a, b));
		}
		solve();
	}
}