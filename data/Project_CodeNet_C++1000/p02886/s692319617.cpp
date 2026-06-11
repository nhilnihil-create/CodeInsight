#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1],sum=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            sum+=a[i]*a[j];
        }
    }

    cout<<sum<<endl;
    exit(0);
}
