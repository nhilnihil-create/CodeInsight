#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	long long x,k;
	long long l,s;
	scanf("%lld %lld",&x,&k);
	l=0; s=0;
	if(x<0){
		x=x*-1;
	}
	l=x-((x/k)*k);
	s=(x-((x/k+1)*k))*-1;
	if(s<l){
		printf("%lld\n",s);
	}
	else{
		printf("%lld\n",l);
	}
	return 0;
}