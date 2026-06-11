#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
	long long a,b,c;
	scanf("%lld%lld.%lld",&a,&b,&c);
	printf("%lld\n",a*b+a*c/100);
}