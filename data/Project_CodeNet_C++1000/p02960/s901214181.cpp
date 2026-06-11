#include <cstdio>
#define maxn 100005
#define ANS_MOD 1000000007ull
#define MOD 13
using namespace std;

typedef unsigned long long ULL;

char s[maxn];
ULL dp[maxn][MOD];

int main(int argc, char** argv)
{
	ULL res = 0ull;
	char c;
	dp[0][0] = 1ull;
	int i = 0;
	while((c = getchar()) != '\n')
	{
		int digit;
		if(c == '?') digit = -1;
		else digit = c - '0';
		for(int j=0; j<10; j++)
			if(digit == -1 || digit == j)
				for(int k=0; k<MOD; k++)
				{
					ULL& x = dp[i + 1][(k * 10 + j) % MOD];
					x += dp[i][k];
					x %= ANS_MOD;
				}
		i ++;
	}
	res = dp[i][5];
	printf("%llu\n", res);
	return 0;
}