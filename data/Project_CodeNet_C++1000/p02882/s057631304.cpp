#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for0(n) for(i=0; i<(n); i++)
#define for1(n) for(i=1; i<=(n); i++)
#define PI acos(-1)

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double _,i,j,n,a,b,e,k,u,t,x=1,m,y,q,f=1,c=0,d=0,l,p,z,o,r,g;
    string ss,s;
    cin>>a>>b>>x;
    r=a*a*b;
    r-=x;
    if(r<=x)
    {
        r/=a;
        p=(2*r)/a;
        p/=a;
        cout<<fixed<<setprecision(10)<<atan(p)*180/PI<<endl;
    }
    else
    {
        r=x;
        r/=a;
        p=(2*r)/b;
        p/=b;
        cout<<fixed<<setprecision(10)<<90.0-(atan(p)*180/PI)<<endl;
    }


}

