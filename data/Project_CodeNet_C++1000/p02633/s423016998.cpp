#include<stdio.h> 
#define it register int
#define ct const int
#define il inline 
const int N=1000005;
int n;
il int gcd(ct a,ct b){return !b?a:gcd(b,a%b);}
int main(){ 
	scanf("%d",&n),printf("%d\n",360/gcd(n,360));
	return 0;
}
