#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double x1,x2,y1,y2;
    cin>>x1>>x2>>y1>>y2;
    double a,b;
    a=(y1-x1)*(y1-x1);
    b=(y2-x2)*(y2-x2);
    cout<<fixed<<setprecision(7)<<sqrt(a+b)<<'\n';
}
