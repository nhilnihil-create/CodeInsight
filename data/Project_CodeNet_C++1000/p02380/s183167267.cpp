# include <iostream>
# include <stdint.h>
# include <stdio.h>
# include <math.h>
# include <algorithm>
# include <string>
using namespace std;


int main(){
	double a,b,c,s,l,h;
    cin >>a>>b>>c;
    double pi = 3.141592653589793;
    c = c*pi/180;
    s =a*b*0.5* sin(c);
    l = pow(pow(a,2) + pow(b,2) - 2*a*b*cos(c),0.5) +a +b;
    h = b*sin(c);
    printf("%.7f\n",s);
    printf("%.7f\n",l);
    printf("%.7f\n",h);

	return 0;
}

