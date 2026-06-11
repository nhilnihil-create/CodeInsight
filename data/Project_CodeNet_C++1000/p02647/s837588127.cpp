#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,k,v[300001],mars[300001],nrop;
bool allequal(ll v[300001])
{
    for(int j=1;j<n;j++)
        if(v[j]!=n)
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    while(nrop<k&&allequal(v)==0)
    {
        nrop++;
        for(int i=1;i<=n;i++)
            mars[i]=0;
        for(int i=1;i<=n;i++)
        {
            mars[max(1LL,i-v[i])]++;
            mars[min(n+1,i+v[i]+1)]--;
        }
        for(int i=1;i<=n;i++)
        {
            mars[i]=mars[i-1]+mars[i];
            v[i]=mars[i];
        }
    }
    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
    return 0;
}
