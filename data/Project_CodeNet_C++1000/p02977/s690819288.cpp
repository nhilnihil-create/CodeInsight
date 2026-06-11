#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int main(){
	int n;
	scanf("%d", &n);
	if (n == (n & -n)) { printf("No\n"); return 0; }
	printf("Yes\n");
	if (n & 1){
		for (int i = 2; i <= n; i += 2)printf("1 %d\n", i);
		for (int i = n + 3; i <= n << 1; i += 2)printf("1 %d\n", i);
		for (int i = 2; i < n; i += 2)printf("%d %d\n", i, i + 1);
		for (int i = n + 2; i < n << 1; i += 2)printf("%d %d\n", i, i + 1);
		printf("3 %d\n", n + 1);
	}else {
		int x = 20;
		while (!(n >> x & 1))--x;
		x = 1 << x;
		int z = n ^ x;
		printf("%d %d\n", x, x + 1);
		printf("%d %d\n", x + n, x + n + 1);
		printf("%d %d\n", 1, x);
		printf("%d %d\n", 1, x + n + 1);
		printf("%d %d\n", n + 1, x + 1);
		printf("%d %d\n", n, x);
		printf("%d %d\n", n + n, z);
		for (int i = 2; i < n; i += 2)if (i != x)printf("%d %d\n", i, x), printf("%d %d\n", i, i + 1);
		for (int i = n + 3; i < n << 1; i += 2)if (i != n + x + 1)printf("%d %d\n", i, i - 1), printf("%d %d\n", i, x + 1);
	}
}