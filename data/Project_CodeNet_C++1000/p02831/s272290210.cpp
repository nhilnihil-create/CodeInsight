#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	long long a,b,x,i;
	scanf("%lld %lld",&a,&b);
	if(a>b){
		x=a;
		a=b;
		b=x;
	}
	for(i=a;i<=10000000000;i=i+a){
		if(i%b==0)	break;
	}
	printf("%lld",i);
	return 0;
}
