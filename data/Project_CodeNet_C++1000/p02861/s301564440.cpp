#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    long long n,x[10],y[10],i,total=1,j,l,dx,dy,k;
    double total2=0.0,p,q;
    cin>>n;
    for(j=2;j<=n;j++)
    {
        total*=j;
    }
    l=total/n;
    q=(double)l;
    for(i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];        
    }
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            dx=x[j]-x[i];
            dy=y[j]-y[i];
            k=(dx*dx)+(dy*dy);
            p=sqrt((double)k);
            total2+=(p*q*2.0);
        }
    }
    cout<<fixed<<showpoint<<setprecision(10)<<total2/(double)total<<endl;
    return 0;
}