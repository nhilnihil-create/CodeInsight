#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main(){
    double a, b, x;
    cin >> a >> b >> x;

    x = x/a;
    if(x >= a*b/2){
        printf("%.10f\n", atan(2*(a*b-x)/(a*a))*180/(M_PI));
    }
    else{
        printf("%.10f\n", atan(b*b/(2*x))*180/(M_PI));
    }

    return 0;
}