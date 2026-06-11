#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int p=(n-1)/2;
		printf("%d\n",p);
	}
	return 0;
}