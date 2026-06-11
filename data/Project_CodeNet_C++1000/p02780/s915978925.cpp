#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
    long long n,i,k,j;
    double max=0.0,x,total,a[200005],y;
    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        cin>>a[i];
        max=max+((a[i]*1.0*(a[i]+1.0))/2.0)/(a[i]*1.0);
    }
    total=max;
    for(j=k+1;j<=n;j++)
    {
        cin>>a[j];
        x=((a[j-k]*(a[j-k]+1.0)*1.0)/2.0)/(a[j-k]*1.0);
        y=((a[j]*1.0*(a[j]+1.0))/2.0)/(a[j]*1.0);
        total-=x;
        total+=y;
        if(total>max)
        {
            max=total;
        }        
    }
    cout<<fixed<<showpoint<<setprecision(12)<<max<<endl;
    return 0;
}