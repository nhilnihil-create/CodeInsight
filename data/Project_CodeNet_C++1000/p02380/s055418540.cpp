#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
int main(void){
    // Your code here!
    long double a,b,c,d,e,f,g;
    string A;
    cin>>a>>b>>c;
    c=c*acos(-1)/180;
    e=(a*b*sin(c))/2;
    f=sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(c));
    //cout<<printf("%.10lf\n", sqrt(e))<<endl;
    //e=sqrt(e);
    // cout << f << endl;
    std::cout << setprecision(16) << e <<endl;
    std::cout << setprecision(16) << a + b + f<<endl;
    std::cout << setprecision(16) << e*2/a <<endl;
    return 0;
}

