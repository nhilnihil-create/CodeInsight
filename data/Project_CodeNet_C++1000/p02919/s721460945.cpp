#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define sort(a) sort(a.begin(),a.end())
#define MOD (int)(1e9+7)
#define EPS 1e-8
#define INF (int)(1e9+1e7)
#define INFL (ll)(1e18)
typedef long long ll;
using namespace std;
int main()
{
    int n;
    cin >> n;
    multiset<ll>used;
    used.insert(-1);used.insert(-1);
    used.insert(n);used.insert(n);

    vector<ll>ind(n,-1);
    rep(i,n){
        ll p;
        cin >> p;--p;
        ind[p]=i;
    }
    ll ans=0;
    for(ll i = n-1;i>=0;i--){
        ll k = ind[i];
        used.insert(k);
        auto itr =used.lower_bound(k);
        ll c =*(++itr);
        ll d =*(++itr);
        --itr;--itr;
        ll b =*(--itr);
        ll a =*(--itr);
        
        ans+=(i+1)*((b-a)*(c-k)+(d-c)*(k-b));
    }

    cout << ans << endl;
}