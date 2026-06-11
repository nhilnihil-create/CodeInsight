#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,k,t,n,m,l,x,y,z;
	double b;
	long long a,c,d;
    while(scanf("%lld%lf",&a,&b)!=EOF){
    	d=b*100+0.1;
    	c=a*d/100;
    	printf("%lld\n",c);
	}
    return 0;
}