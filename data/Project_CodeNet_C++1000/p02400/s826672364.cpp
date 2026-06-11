#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(void){

    double r, p;

    cin >> r;

    p = acos(-1);
    
    printf("%.7lf %.7lf",pow(r,2) * p,2 * p * r);

return 0;

}