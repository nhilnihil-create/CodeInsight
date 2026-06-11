#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main() {
    while(1){     
    	int i,n;
        int v;
        double avg, dev, sum = 0.0, sum2 = 0.0;
     	cin >> n;
     	if(n==0)break;
        for (i = 0; i < n; i++) {
           cin>> v;
           sum  += v;
           sum2 += v*v;
        }
        avg = sum/n;
        dev = sqrt(sum2/n - avg*avg);
        printf("%.10f\n", dev);
    }

}         // ??????=3.375, ?¨??????????=0.540