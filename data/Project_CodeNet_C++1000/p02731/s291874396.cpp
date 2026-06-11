#include<bits/stdc++.h>
using namespace std;
int main()
{
 double l,a,b,c;
 cin>>l;
a=l/3.0;
b=(l-a)/2;
c=l-(a+b);
c=a*b*c;
cout<<fixed<<setprecision(10)<<c<<endl;

}
