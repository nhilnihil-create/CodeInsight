#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int main(){
    double x1, x2;
    double y1, y2;
    double a1,a2;
    
    cin >> x1 >> y1 >> x2 >> y2;
    
    a1 = (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1) ;
    a2 = sqrt(a1);
    
    printf("%12.8f\n",a2);
    
    return 0;
}