#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define N_MAX 300001

void solv()
{
	int N; scanf("%d", &N);
	int cnt[N_MAX];
	fill(cnt, cnt + N, 0);
	for (int i = 0; i < N; i++){
		int a; scanf("%d", &a); a--;
		cnt[a]++;
	}

	sort(cnt, cnt + N);

	int sum = 0, head = 0, len[N_MAX];
	for (int op = 1; op <= N; op++){
		for (; head < N; head++){
			if (cnt[head] < op){
				sum += cnt[head];
			}
			else{
				break;
			}
		}
		len[op] = N - head + sum / op;
	}

	reverse(len + 1, len + N + 1);

	for (int K = 1; K <= N; K++){
		printf("%d\n", (len + N + 1) - lower_bound(len + 1, len + N + 1, K));
	}

	return;
}

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	solv();

	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}