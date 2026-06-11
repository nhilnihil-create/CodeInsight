#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define N_MAX 2001
#define MOD 1000000007

int N, M;
int S[N_MAX], T[N_MAX];
long long int memo[N_MAX][N_MAX];

long long int func(int x, int y)
{
	if (x < 0) return 0;
	if (y < 0) return 0;
	if (-1 != memo[x][y]){
		return memo[x][y];
	}

	long long int ret = 0;
	ret = (ret + func(x - 1, y)) % MOD;
	ret = (ret + func(x, y - 1)) % MOD;
	ret = (ret - func(x - 1, y - 1) + MOD) % MOD;

	if (S[x] == T[y]){
		ret = (ret + func(x - 1, y - 1) + 1) % MOD;
	}

	return memo[x][y] = ret;
}

void solv()
{
	scanf("%d%d", &N, &M);
	int tail = 0;
	for (int i = 0; i < N; i++){
		scanf("%d", S + i);
	}
	for (int i = 0; i < M; i++){
		scanf("%d", T + i);
	}

	for (int i = 0; i < N_MAX; i++){
		fill(memo[i], memo[i] + N_MAX, -1);
	}

	printf("%lld", func(N-1, M-1) + 1);

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