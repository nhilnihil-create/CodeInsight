#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,mx=-1,mn=101,ans=10000000;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    long long int sum=0;
    for(int j=1;j<101;j++)
    {
        sum=0;
        for(int i=0;i<n;i++)
          sum+=(j-a[i])*(j-a[i]);
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}

