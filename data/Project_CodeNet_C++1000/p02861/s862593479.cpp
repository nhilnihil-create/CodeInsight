#include<bits/stdc++.h>
using namespace std;
double x[10],y[10],ans=0,n_=1;
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        n_*=i;
        cin>>x[i]>>y[i];
    }
    double k=1;
    for(int i=1;i<=n-2;i++)
        k*=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            double temp=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            ans+=(temp*=2.0*(n-1)*k);
        }
    }
    ans/=n_;
    cout<<fixed<<setprecision(10)<<ans;
}