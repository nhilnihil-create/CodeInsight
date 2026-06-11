#include<cstdio>
using namespace std;
long long a,b,c;
int main(){
	scanf("%lld%lld%lld",&a,&b,&c);long long d=c-a-b;
	if(a+b>=c){
		printf("No");
		return 0;
	}
	if(4*a*b<d*d) printf("Yes");
	else printf("No");
	return 0;
}