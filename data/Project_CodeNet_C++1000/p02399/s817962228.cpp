#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	long int a,b;
	long int d,r;
	double f;
	std::cin>> a>>b;
	d=a/b;
	r=a%b;
	f=(double)a/b;
	std::cout << d<<" "<<r<<" "<<fixed <<setprecision(5) << f <<std::endl;
	return 0;
}