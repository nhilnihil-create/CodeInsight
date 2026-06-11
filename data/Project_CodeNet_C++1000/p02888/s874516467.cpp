#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());

    ll ans=0;

    for(int i=0;i<n-2;i++)for(int j=i+1;j<n-1;j++)
    {
        int l=j,r=n;
        for(int m=l+(r-l)/2;m!=l;m=l+(r-l)/2)
        {
            if(a[i]+a[j]>a[m])l=m;
            else r=m;
        }
        ans+=l-j;
    }

    cout<<ans<<"\n";

    return 0;
}
