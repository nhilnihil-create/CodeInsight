#include <cstdio>
using namespace std;

const int md = (1 << 23) * 17 * 7 + 1;

inline int add(int a, int b) 
{
	a += b;
	if (a >= md) a -= md;
	return a;
}
inline int mul(int a, int b) 
{
	return (long long)a * b % md;
}

const int N = 3000;
int a[N];
int dp[N + 1][N + 1];

int main() 
{
	int n, s;
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= s; ++j) {
			dp[i][j] = mul(dp[i - 1][j], 2);
			if (j >= a[i - 1]) dp[i][j] = add(dp[i][j], dp[i - 1][j - a[i - 1]]);
		}
	}
	printf("%d\n", dp[n][s]);
	return 0;
}
