#include<bits/stdc++.h>
using namespace std;
int res;
int solve(double a,double b)
{
    a=pow(a,2);
    b=pow(b,2);
    //cout<<a<<" "<<b<<"\n";
    double ans=sqrt(a+b);
   // cout<<ans<<"\n";
   if(ans<=res)
    return 1;
    return 0;
}
int main()
{
    int a,ret=0,ans=0;
    double t,c,x,y;
    cin>>a>>res;
    while(a--)
    {

        cin>>x>>y;
        int ret=solve(x,y);
        if(ret)
            ans++;

    }
    cout<<ans<<"\n";

    return 0;
}
