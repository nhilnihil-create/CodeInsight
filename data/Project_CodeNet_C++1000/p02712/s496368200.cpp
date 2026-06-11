#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	double n,sum=0,flag=0;
	scanf("%lf",&n);
	for(int i=1;i<=n;i++)
	{
		if(i%3==0||i%5==0||i%15==0)
		  flag=1;
		else
		  sum+=i;
	}
	printf("%.0lf\n",sum);
	return 0;	
}