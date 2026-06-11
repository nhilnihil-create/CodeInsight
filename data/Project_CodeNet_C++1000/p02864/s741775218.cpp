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

#define N_MAX 310
#define INF 500000000000

int H[N_MAX];
long long int memo[N_MAX][N_MAX];

long long int func(int last, int cnt)
{
	if (1 == cnt){
		return H[last];
	}
	if (0 == last){
		return INF;
	}
	if (-1 != memo[last][cnt]){
		return memo[last][cnt];
	}

	long long int ret = INF;
	for (int i = 0; i < last; i++){
		ret = min(ret, func(i, cnt - 1) + max(0, H[last] - H[i]));
	}

	return memo[last][cnt] = ret;
}

void solv()
{
	int N, K; scanf("%d%d", &N, &K);

	for (int i = 0; i < N; i++){
		scanf("%d", H + i);
	}

	for (int i = 0; i < N; i++){
		fill(memo[i], memo[i] + N + 1 , -1);
	}

	long long int ret = INF;
	if (N == K){
		ret = 0;
	}
	else{
		for (int i = 0; i < N; i++){
			ret = min(ret, func(i, N - K));
		}
	}


	printf("%lld", ret);

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