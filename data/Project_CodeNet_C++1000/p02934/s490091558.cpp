#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,a,i;
	double x=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		x+=(double)1/a;
	}
	printf("%lf\n",1/x);
	return 0;
}
