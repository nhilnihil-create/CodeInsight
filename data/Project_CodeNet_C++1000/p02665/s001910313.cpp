#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int a[100050];

void solve()
{
    int n;
    ll ans=1,m=1,sum=0;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(n>0&&a[0]>0||n==0&&a[0]>1)
    {
        cout<<"-1\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        m=min(m<<1,sum);
        ans+=m;
        if(a[i]>m)
        {
            cout<<"-1\n";
            return;
        }
        m-=a[i];
        sum-=a[i];
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}