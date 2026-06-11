#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	int a, b, d, r;
	double f;
	cin >>a>>b;
	r=a%b;
	d=(a-r)/b;
	f=(double)a/b;
	cout <<d<<" "<<r<<" " <<fixed << setprecision(10) << f << endl;;
    
	
	return 0;
}