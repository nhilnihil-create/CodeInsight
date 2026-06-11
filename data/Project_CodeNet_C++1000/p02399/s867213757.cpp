#include<iostream>
#include<cstdio>

double a = 0  , b = 0 ,  f = 0 ;
int aa = 0 , bb = 0 , d = 0 , r = 0 ;

int main()
{
	std::cin >> a >> b ;
	aa = a ;
	bb = b ;
	d = aa / bb ;
	r = aa % bb ;
	f = a / b ;
	std::cout << d << " " << r << " " ;
	printf("%.5f\n", f);
}