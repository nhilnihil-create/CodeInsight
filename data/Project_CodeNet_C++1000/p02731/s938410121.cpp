#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double l,a,V;
    cin>>l;
    a=l/3.0;
    V=(a*a*a);
cout<<fixed<<showpoint<<setprecision(12)<<V<<endl;
    return 0;
}