#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7,INF=1e18;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll> a(n),b(n,0),c(n,0);
        for(int i=0;i<n;i++)
        cin>>a[i];
        while(k--)
        {
            for(ll i=0;i<n;i++)
            {
                b[max(i-a[i],0LL)]++;
                if(min(i+a[i],n-1)!=n-1)
                {
                    b[min(i+a[i],n-1)+1LL]--;
                }
            }
            for(int i=1;i<n;i++)
            b[i]+=b[i-1];
            if(a==b)
            break;
            a=b;
            b=c;
        }
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    }
    return 0;
}