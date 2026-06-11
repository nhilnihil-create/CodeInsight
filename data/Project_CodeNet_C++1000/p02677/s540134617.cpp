#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238462643383279

int main()
{
    int a,b,h,m;
    cin>>a>>b>>h>>m;
    long double H,M,red,s,ans;
    H=h*30;
    M=m*6;
    H=H+M/12;
    s=abs(H-M);
    red=cos(s*PI/180);
    ans=((a*a+b*b)-2*a*b*red);
    ans=sqrt(ans);
   cout<<fixed<<showpoint;
   cout<<setprecision(15);
   cout<<ans<<endl;
    return 0;
}