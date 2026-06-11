#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
int n,m;
int main()
{
	cin >> n; m = log2(n);
	if(n == (1 << m)) {puts("No"); return 0;}
	puts("Yes");
	printf("%d %d\n",1,2);
	printf("%d %d\n",2,3);
	printf("%d %d\n",3,n + 1);
	printf("%d %d\n",n + 1,n + 2);
	printf("%d %d\n",n + 2,n + 3);
	for(int i = 2;i * 2 + 1 <= n;i ++)
	{
		printf("%d %d\n",1,2 * i);
		printf("%d %d\n",1,2 * i + 1);
		printf("%d %d\n",2 * i,2 * i + n + 1);
		printf("%d %d\n",2 * i + 1,2 * i + n);
	}
	if((n & 1) == 0)
	{
		for(int i = 2;i <= n;i ++)
		{
			if(i == 3) continue;
			int y = (i ^ n ^ 1);
			if(y == 3 || y > n) continue;
			printf("%d %d\n",n,i);
			printf("%d %d\n",2 * n,y);
			break;
		}
	}
	return 0;
}