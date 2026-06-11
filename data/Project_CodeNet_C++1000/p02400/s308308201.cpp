#include <iostream>
#include <cstdio>
#include <cmath>
int main(){
	double r,s,l;
    std::cin >> r;
	s=M_PI*r*r;
	l=2*M_PI*r;

    printf("%5lf %5lf\n",s,l);
	return 0;
}