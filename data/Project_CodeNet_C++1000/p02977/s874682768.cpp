#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int N; scanf("%d",&N);
	int t;
	for(int i = 1;i <= N;t = i,i <<= 1)
		if(N == i)
		{
			printf("No\n");
			return 0;
		}
	if(N == 3)
	{
		printf("Yes\n");
		for(int i = 1;i <= 5; ++ i)
			printf("%d %d\n",i,i + 1);
	}
	else
	{
		puts("Yes");
		for(int i=2; i<N; i+=2)
		{
			printf("%d %d\n", 1, i);
			printf("%d %d\n", i, i+1);
			printf("%d %d\n", 1, N+i+1);
			printf("%d %d\n", N+i+1, N+i);
		}
		printf("%d %d\n", N+1, 3);
		if(!(N&1))
		{
			printf("%d %d\n", N, N^t);
			printf("%d %d\n", N*2, N+(t^1));
		}
	}
}