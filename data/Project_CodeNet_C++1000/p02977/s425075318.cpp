#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, cn;

int main()
{
	scanf("%d", &n);
	if(n == (n & -n)) {
		printf("No\n");
		return 0;
	}
	
	printf("Yes\n");
	
	cn = n - (n + 1) % 4;
	rep1(i, cn) printf("%d %d\n", i, i == cn ? n + 1 : i + 1);
	rep1(i, cn - 1) printf("%d %d\n", n + i, n + i + 1);
	
	if(n - cn == 1) {
		int cur = n & -n;
		printf("%d %d\n", cn + 1, cur + 1);
		printf("%d %d\n", n + cn + 1, (n ^ cur));
	} else if(n - cn == 2) {
		printf("%d %d\n", cn + 1, cn + 2);
		printf("%d %d\n", cn + 2, 1);
		printf("%d %d\n", n + cn + 1, n + cn + 2);
		printf("%d %d\n", n + cn + 1, 1);
	} else if(n - cn == 3) {
		printf("%d %d\n", cn + 1, cn + 2);
		printf("%d %d\n", cn + 2, 1);
		printf("%d %d\n", n + cn + 1, n + cn + 2);
		printf("%d %d\n", n + cn + 1, 1);
		printf("%d %d\n", cn + 3, cn + 2);
		printf("%d %d\n", n + cn + 3, 2);
	}
	return 0;
}