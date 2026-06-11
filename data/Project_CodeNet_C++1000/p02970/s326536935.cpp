#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,b,x=0;
	scanf("%d%d",&n,&b);
	x=n%(b*2+1);
	if(x==0) printf("%d\n",n/(b*2+1));
	else printf("%d\n",n/(b*2+1)+1);
	return 0;
}
