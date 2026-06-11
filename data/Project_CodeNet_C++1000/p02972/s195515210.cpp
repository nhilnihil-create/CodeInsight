#include <bits/stdc++.h>
using namespace std;

int a[200010];
int b[200010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];

    for(int i=n;i>0;i--)
    {
        int cnt=0;
        for(int j=2;i*j<=n;j++)if(b[i*j-1])cnt++;
        cnt%=2;
        b[i-1]=(cnt+a[i-1])%2;
    }

    int ans=0;
    for(int i=0;i<n;i++)if(b[i])ans++;
    cout<<ans<<"\n";
    for(int i=0;i<n;i++)if(b[i])cout<<i+1<<" ";
    cout<<"\n";

    return 0;
}
