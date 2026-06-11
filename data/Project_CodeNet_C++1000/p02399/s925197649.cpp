#include <iostream>
#include <cstdio>
int main(){
	int a,b,c,d,r;
	double f;
    std::cin >> a >> b;
	d=a/b;
	r=a%b;
	f=(double)a/(double)b;
    printf("%d %d %5lf\n",d,r,f);
	return 0;
}