# include <iostream>
# include <stdint.h>
# include <stdio.h>
# include <math.h>
# include <algorithm>
# include <string>
using namespace std;


int main(){
	double a,b,c,d,x;
cin >>a>>b>>c>>d;    
    x = pow(pow(a-c,2) + pow(b-d,2),0.5);
    printf("%.7f\n",x);
    cout <<"\n";



	return 0;
}

