#include <iostream>
#include <cstdio>
using namespace std;
int main(void){
    // Here your code !
    
    double a,b,c;
    double pi=3.14159265358979323846  ;
    cin>>a;
    b=2*a*pi;
    c=a*a*pi;
    
    std::printf("%.6f %.6f",c,b);
    
    return 0;
}