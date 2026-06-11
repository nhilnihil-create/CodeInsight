#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, M, V, P, A[101010];

bool check(int X)
{
	int hoge = N - P;
	if (X < hoge) ++hoge;

	i64 ss = 0;
	for (int i = 0; i < hoge; ++i) {
		if (A[i] > A[X]) {
			int dd = A[i] - A[X];
			if (dd > M) return false;
			ss += dd;
		}
	}
	if (ss > (i64)M * (N - V)) return false;
	return true;
}

int main()
{
	scanf("%d%d%d%d", &N, &M, &V, &P);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	sort(A, A + N);

	int left = 0, right = N - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	printf("%d\n", N - right);
	return 0;
}
