#include <iostream>
#include<stdio.h>
using namespace std;
int main(void){
    // Your code here!
    int a,b,x,y;
    cin>>a>>b;
    double z;
    x = a/b;
    y = a%b;
    z = 1.0 * a/b;
    cout<<x<<" "<<y<<" ";
    printf("%.6lf\n", z);
}

