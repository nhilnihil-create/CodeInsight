#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    double a=x1-x2;
    double b=y1-y2;
    double c=a*a+b*b;
    double d=sqrt(c);
    cout<<fixed<<d<<endl;
    
    return 0;
}