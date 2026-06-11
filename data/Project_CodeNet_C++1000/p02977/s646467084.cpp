#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int n;
	scanf("%d",&n);
	int T=n;
	while(T%2==0) T/=2;
	if(T==1) puts("No");
	else
	{
		puts("Yes");
		int z=n;
		if(z%2==0) z--;
		for(int i=2;i<=z;i+=2)
		{
			printf("%d %d\n",1,i);
			printf("%d %d\n",i,i+1);
			printf("%d %d\n",1,n+i+1);
			printf("%d %d\n",n+i+1,n+i);
		}
		printf("%d %d\n",n+1,3);
		if(n%2==0)
		{
			for(int i=20;i>=0;i--)
			{
				if(n>>i&1)
				{
					int A=(1<<i),B=n-A;
					printf("%d %d\n",A,n);
					printf("%d %d\n",B+n+1,2*n);
					break;
				}
			}
		}
	}
	return 0;
}
