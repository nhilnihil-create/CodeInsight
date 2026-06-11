#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++)
    cin>>a[i];
    int l=a[0]; int r=a[0];
    for(i=0;i<n;i++)
    {
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    int sum=1000000000;
    for(i=l;i<=r;i++)
    {
        int ans=0;
        for(int j=0;j<n;j++)
         ans+=(a[j]-i)*(a[j]-i);
      sum=min(sum,ans);
    }
    cout<<sum<<"\n";
}