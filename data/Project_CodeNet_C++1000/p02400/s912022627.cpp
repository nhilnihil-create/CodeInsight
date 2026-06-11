#include<iostream>
#include<iomanip>
using namespace std;
const double pi=3.141592653589;
int main()
{
double r;
cin>>r;
cout<<fixed<<setprecision(6)<<r*r*pi<<" "<<fixed<<setprecision(6)<<2.000000*r*pi<<endl;
return 0;
}