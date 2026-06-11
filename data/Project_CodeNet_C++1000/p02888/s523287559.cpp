#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=1e9+7;
int a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int x=a[i]+a[j];
            int p=lower_bound(a+1,a+1+n,x)-a;
            p--;
            ans+=p-j;
        }
    }
    cout<<ans<<'\n';


}
