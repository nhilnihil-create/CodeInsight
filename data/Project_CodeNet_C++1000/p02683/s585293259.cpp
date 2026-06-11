#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>

class node {
    public:
    ll cost;
    ll algo[12];

    bool operator<(const node b) {
        return cost<b.cost;
    }

};

bool canminus(ll cost[], ll m, ll a[], ll x)
{
    for(ll i=0;i<m;i++)
        if(cost[i]-a[i]<x)
            return false;
    return true;
}

void dominus(ll cost[], ll m, ll a[])
{
    for(ll i=0;i<m;i++)
        cost[i]-=a[i];
}

void test_case()
{
    ll n,m,x;
    cin>>n>>m>>x;
    vector<node> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i].cost;
        for(int j=0; j<m; j++) {
            cin>>a[i].algo[j];
        }
    }
    ll ans=INT_MAX;
    for(ll mask=0; mask<(1<<n); mask++) {
        vector<ll> level(m,0);
        ll cost=0;

        for(ll i=0;i<n;i++) {
            if((mask>>i)&1) {
                cost+=a[i].cost;
                for(ll j=0;j<m;j++)
                    level[j]+=a[i].algo[j];
            }
        }
        bool ok=true;
        for(ll j=0;j<m;j++)
        if(level[j]<x) {
            ok=0;
            break;
        }
        if(ok) {
            ans=min(ans, cost);
        }
    }
    if(ans==INT_MAX)
        cout<<"-1\n";
    else
        cout<<ans<<"\n";
}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
