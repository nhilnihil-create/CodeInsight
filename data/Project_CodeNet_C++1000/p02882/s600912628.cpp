#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=1e9+7;
const double pi=3.1415926535;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a,b,x;
    cin>>a>>b>>x;
    double v=a*a*b;
    double yu=v-x;
    if(yu<=x)
    {
        double jiao=atan(yu*2.0/(a*a*a));
        jiao=jiao/pi*180.0;
        cout<<fixed<<setprecision(10)<<jiao<<'\n';
    }
    else
    {
        double jiao=atan(x*2.0/(a*b*b));
        jiao=jiao/pi*180.0;
        jiao=90.0-jiao;
        cout<<fixed<<setprecision(10)<<jiao<<'\n';
    }



}
