#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,x[50],i;
	double y=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	sort(x,x+n);
	y=x[0];
	for(i=1;i<=n-1;i++){
		y=(y+x[i])/2;
	}
	printf("%lf\n",y);
	return 0;
}
