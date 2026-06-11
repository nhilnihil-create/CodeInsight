#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
   double a,b,c,d;
   double tmp,e;
   cin>>a>>b>>c>>d;
   tmp=(c-a)*(c-a)+(d-b)*(d-b);
   e=sqrt(tmp);
   cout<<fixed<<setprecision(15)<<e<<endl;
    return 0;
}
