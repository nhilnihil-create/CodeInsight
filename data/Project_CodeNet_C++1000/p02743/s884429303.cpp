#include <cstdio>
using namespace std;

int main()
{
	long long a , b , c ;
	scanf("%lld %lld %lld", &a, &b, &c) ;
	long long d = c - a - b ;
	if(d < 0) 
	puts("No") ;
	else 
	puts((d * d > 4LL * a * b) ? "Yes" : "No") ;
	return 0 ;
}