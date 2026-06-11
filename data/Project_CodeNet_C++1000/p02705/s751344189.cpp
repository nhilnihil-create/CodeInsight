#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double pi=acos(-1);
int main()
{
    double r;
    cin>>r;
    cout<<fixed<<showpoint<<setprecision(20)<<(2.0*pi*r)<<endl;
    return 0;
}