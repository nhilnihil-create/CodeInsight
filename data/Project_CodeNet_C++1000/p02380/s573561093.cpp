#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

#define K(w) sin(w/(180/3.141592653589793238462643383279502884197))
#define L(w) cos(w/(180/3.141592653589793238462643383279502884197))

int main(){
    double a,b,c;
    cin>>a>>b>>c;
    cout<<fixed<<setprecision(50)<<a*K(c)*b/2<<endl;
    cout<<fixed<<setprecision(50)<<sqrt(pow(a*K(c),2)+pow(b-a*L(c),2))+a+b<<endl;
    cout<<fixed<<setprecision(50)<<b*K(c)<<endl;
    return 0;
}