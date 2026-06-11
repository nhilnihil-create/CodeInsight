# include <iostream>
# include <stdint.h>
# include <stdio.h>
# include <math.h>
#include <cstdlib>
# include <algorithm>
# include <string>
using namespace std;


int main(){
    int n;
    double  max =0,sum1=0,sum2 =0,sum3 =0,t;
    int x[1000] ={},y[1000] ={};
    cin >>n;
    for(int i=0;i<n;i++){
        cin >>x[i];
    }
    for(int i=0;i<n;i++){
        cin >>y[i];
    }
    for(int i=0;i<n;i++){
        t = fabs(x[i] - y[i]);
        sum1 += t;
        sum2 += pow(t,2);
        sum3 +=pow(t,3);
        if(t >max) max = t;
    }
    printf("%.7f\n",(double)sum1);
    printf("%.7f\n",pow(sum2,0.5));
    printf("%.7f\n",pow(sum3,0.333333333333333));
    printf("%.7f\n",(double)max);
	return 0;
}

