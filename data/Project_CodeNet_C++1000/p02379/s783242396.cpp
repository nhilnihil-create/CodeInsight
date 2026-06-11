#include <iostream>
#include <cmath>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long double a,b,c,d,e,f,g;
    string A;
    cin>>a>>b>>c>>d;
    e=pow(a-c,2)+pow(b-d,2);
    //cout<<printf("%.10lf\n", sqrt(e))<<endl;
    e=sqrt(e);
    // cout << f << endl;
    std::cout << std::setprecision(20) << e;
    return 0;
}

