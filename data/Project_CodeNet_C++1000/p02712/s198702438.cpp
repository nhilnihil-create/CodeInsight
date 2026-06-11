#include<cstdio>
int main()
{
	long long n,i,a;
	a=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		if(i%3!=0||i%5!=0){
			if(i%3!=0&&i%5!=0) a+=i;
		}
	}
	printf("%lld\n",a);
	return 0;
}
