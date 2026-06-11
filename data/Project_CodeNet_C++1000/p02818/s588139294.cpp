#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void)
{
	long long a,b,k,i;
	scanf("%lld %lld %lld",&a,&b,&k);
	if(a-k<=0){
		k-=a;
		a=0;
		if(b-k<=0)	b=0;
		else	b-=k;
	}
	else	a-=k;
	printf("%lld %lld\n",a,b);
	return 0;
}
