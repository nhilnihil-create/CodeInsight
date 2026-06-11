#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
     double l;
    cin>>l;
    long double v=l/3;
    long double m=(v*v*v);
    cout<<fixed<<setprecision(12)<<m<<endl;
    return 0;
}
