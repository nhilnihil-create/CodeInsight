#include<cstdio>
#include<algorithm>
using namespace std;
int main(void){
	long long a,b,c,s;
	scanf("%lld %lld %lld",&a,&b,&c);
	s=a/(b+c)*b;
	if(a%(b+c)>b){
		s+=b;
	}
	else{
		s+=a%(b+c);
	}
	printf("%lld\n",s);
	return 0;
}