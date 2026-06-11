#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,k,v[2000001],ans,suma,sm[2000001];
map<ll,ll> f;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        suma+=v[i];
        ll s=(suma-i)%k;
        sm[i]=s;
        if(i>=k)
        {
            f[sm[i-k]]--;
        }
        ans+=f[s];
        f[s]++;
    }
    cout<<ans;
    return 0;
}
