#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a1[2005],a2[105],a3[105];
int main()
{
    ll a,b,c,d,e,f,g,i,j,k,l,m,n,o,p,q,r,s,t,tc,u,v,ans;
    long double w,x,y,z;
    string ss;
    cin>>a;ans=0;
    for(i=1;i<=a;i++)
    {
        b=a/i;
        c=i*b*(b+1)/2;
        ans=ans+c;
    }
    cout<<ans;

    return 0;
}
