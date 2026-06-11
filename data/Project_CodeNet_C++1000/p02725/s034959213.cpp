#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;
    cin>>k>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());

    int ans=a[0]+k-a[n-1];

    for(int i=1;i<n;i++) ans=max(ans,a[i]-a[i-1]);

    ans=k-ans;

    cout<<ans<<"\n";

    return 0;
}
