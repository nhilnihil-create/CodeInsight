#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int a[n+1],b[n],sum=0;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];

    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>=b[i])
            sum+=b[i];
        else
        {
            sum+=a[i];
            b[i]=b[i]-a[i];
            if(b[i]>=a[i+1])
            {
                sum+=a[i+1];
                a[i+1]=0;
            }
            else
            {
                sum+=b[i];
                a[i+1]=a[i+1]-b[i];
            }
        }
    }

    cout<<sum<<endl;

}
