#include<bits/stdc++.h>
// __builtin_ctz : no of trailing zeros
#define ll long long
#define pp pair<ll,ll>
#define mod 1000000007
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define sa(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define scan() int n; cin>>n ; int a[n]; for(int i = 0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) cout<<a[i]<<' '
using namespace std;
ll max(ll x, ll y)
{
    return x>y ? x : y;
}
ll min(ll x, ll y)
{
    return x<y ? x : y;
}
ll m;
void _(ll&a , ll b)
{
    a=(a%m+b%m)%m;
    a=(a+m)%m;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;cin >> n >> m;ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];a[i]--;
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << a[i] << " ";
    // }
    cout << "\n";
    map<ll,vector<ll> > mp;ll ans=0;ll d=0;mp[0].push_back(-1);
    for (int i = 0; i < n; ++i)
    {
        _(d,a[i]);
        //if(!d)continue;
        auto it=upper_bound(mp[d].begin(),mp[d].end(),i-m);
        if(it!=mp[d].end())
        {
            ll dd=it-mp[d].begin();
            ans+=mp[d].size()-dd;
        }
        mp[d].push_back(i);
    }
    cout << ans;

    }