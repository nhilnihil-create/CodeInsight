#include<iostream>
using namespace std ;

int main()
	{
	long long x ,y ,ans ,tmp ,tmpx ,tmpy ;
	long long n ,d ;
	scanf("%lld%lld" ,&n ,&d) ;
	d*=d ;
	ans=0 ;
	while(n--)
		{
		scanf("%lld%lld" ,&x ,&y) ;
		tmpx=x*x ;
		tmpy=y*y ;
		tmp=tmpx+tmpy ; 
		if(tmp<=d)
			ans++ ;
		} 
	printf("%lld\n" ,ans) ;
	}