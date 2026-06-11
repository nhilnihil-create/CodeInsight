#include<bits/stdc++.h>
using namespace std;
using ll=double;
int main()
{
    double a,b,h,m;
    cin>>a>>b>>h>>m;

    ll deg1=m*6;
    ll deg2=h*30+(m/2);
    ll deg=abs(deg1-deg2);
    deg=deg/180.0;
    deg=deg*3.1415926535897;
    ll ans=a*a+b*b-2*a*b*cos(deg);
    cout<<fixed<<setprecision(14)<<sqrt(ans)<<endl;

    
    
}