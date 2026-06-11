#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(void){
    double x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    double result =sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    printf("%f",result);
}