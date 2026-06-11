#include <iostream>
#include<stdio.h>
using namespace std;
int main(void){
    // Here your code !
    int x,y,d,r;
    double z;
    cin>>x>>y;
    d=x/y;
    r=x%y;
    z=double(x)/double(y);
    
    printf("%d %d %.5lf\n", d,r,z);
    return 0;
}