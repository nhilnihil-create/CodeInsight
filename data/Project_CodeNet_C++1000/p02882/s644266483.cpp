#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, x;
    cin >> a >> b >> x;
    double pi = acos(-1);
    if(x >= a*a*b/2){
        double c = a, d = b, e = x;
        printf("%.10f",atan(2.0*(c*c*d - e)/(c*c*c)) * 360.0 / (2.0*pi));
    }
    else{
        double c = a, d = b, e = x;
        printf("%.10f",atan(d*d*c/(2*e)) * 360.0 / (2.0*pi));
    }
}