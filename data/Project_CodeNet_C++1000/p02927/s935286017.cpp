#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define long long long
typedef pair<int,int> ii;

int main()
{
	// freopen("input.in", "r", stdin);

	int m, d; scanf("%d %d", &m, &d);

	int res = 0;
	for(int i = 2; i <= 9; i++)
	{
		for(int j = 2; j <= 9; j++)
		{
			if(i*10+j <= d && i*j <= m)
				res++;
		}
	}
	printf("%d\n", res);
}