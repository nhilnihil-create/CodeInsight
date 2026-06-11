#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main()
{
    int a[101],b[101];
    int n;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>b[j];
    }

    double ans;

    for(int i=1;i<=3;i++)
    {
        ans=0;
        for(int j=0;j<n;j++)
        {
            ans+=pow(fabs((double)(a[j]-b[j])),i*1.0);
        }
        ans=pow(ans,1.0/i);
        cout<<fixed<<setprecision(6)<<ans<<endl;
    }

    ans=-1;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,fabs(a[i]-b[i]));
    }
    cout<<ans<<endl;

    return 0;
}

