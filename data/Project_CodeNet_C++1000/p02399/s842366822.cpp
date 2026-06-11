#include <iostream>
#include <stdio.h>
using namespace std;
 
int main(){
	int a,b,c,r;
	double n;
	cin >> a >> b;
	c=a/b;
	r=a%b;
	n=1.0*a/b;
	printf("%d %d %.8lf\n",c,r,n);
    return 0;
}