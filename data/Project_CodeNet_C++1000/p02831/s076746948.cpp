#include<stdio.h>
int main()
{
	long long int a,b,c=0,d=0,i;
	scanf("%lld %lld",&a,&b);
	for(i=1;i<=b;i++){
		c=a*i;
		d=c%b;
		if(d==0){
			printf("%lld\n",c);
			break;
		}
	}
	return 0;
}
