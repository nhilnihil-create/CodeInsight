#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9')	{if(ch == '-')	f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
int main()
{
	int n = read() , m = log2(n);
	if((1 << m) == n) puts("No");
	else
	{
		puts("Yes");
		printf("%d %d\n",1,2);
		printf("%d %d\n",2,3);
		printf("%d %d\n",3,n + 1);
		printf("%d %d\n",n + 1,n + 2);
		printf("%d %d\n",n + 2,n + 3);
		for(int i = 4;i < n;i += 2)
		{
			int j = i + 1;
			printf("%d %d\n",1,i);
			printf("%d %d\n",1,j);
			printf("%d %d\n",i,n + j);
			printf("%d %d\n",j,n + i);
		}
		if(!(n & 1))
		{
			for(int x = 2;x < n;x ++)
			{
				int y = n ^ 1 ^ x;
				if(y > 1 && y < n)
				{
					printf("%d %d\n",n + n,x);
					printf("%d %d\n",n,y);
					break;
				}
			}
		}
	}
	return 0;
}