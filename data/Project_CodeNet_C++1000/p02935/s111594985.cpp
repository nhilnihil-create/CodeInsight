#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,u[50];
	int i,j;
	double x=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&u[i]);
	sort(u,u+n);
	x=u[0];
	for(i=0;i<n-1;i++){
		x=(double)((x+u[i+1])/2);
	}
	printf("%lf\n",x);
	return 0;
}