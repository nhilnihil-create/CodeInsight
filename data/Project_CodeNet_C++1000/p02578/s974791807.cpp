#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long a[n];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long ans=0,t=0;
    for(long long i=0;i<n;i++)
    {
        t=max(t,a[i]);
        ans+=(t-a[i]);
    }
    cout<<ans;
}
