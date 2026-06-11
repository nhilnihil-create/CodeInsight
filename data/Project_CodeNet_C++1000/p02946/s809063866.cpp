#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int a,b,x=0,i;
	scanf("%d%d",&a,&b);
	x=a*2-1;
	for(i=b-(a-1);i<=b+(a-1);i++){
		if(i>=-1000000&&i<=1000000) printf("%d ",i);
	}
	printf("\n");
	return 0;
}
