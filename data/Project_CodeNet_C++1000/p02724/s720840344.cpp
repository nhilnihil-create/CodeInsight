#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int x,a,b,c;
	scanf("%d",&x);
	a=x/500;
	c=x%500;
	b=c/5;
	printf("%d\n",a*1000+b*5);
	return 0;
}