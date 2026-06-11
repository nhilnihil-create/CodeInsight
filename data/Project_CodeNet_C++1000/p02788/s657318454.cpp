#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define vl vector<ll>
#define vi vector<int>

#define ff first
#define ss second

#define pb push_back
#define MOD 1e9+7 
const int nax = 1e6+5;
#define display(v) for(int i =0;i<v.size();++i)cout << v[i] << " "

inline ll add(ll a, ll b){ ll c = a + b; if(c > MOD) c -= MOD; return c; }

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,d,a;
    cin>>n>>d>>a;
    vector<pair<ll,ll> > v(n);
    for(int i =0;i<n;++i){
        ll u,b;  cin>>u>>b;
        v[i] = {u,b};
    }
    sort(v.begin(),v.end());
    vl x(n);
    for(int i =0;i<v.size();++i){
        x[i] = v[i].ff;
    }
    ll ans = 0;
    vl pre(n+1,0);
    for(int i =0;i<n;++i){
        pre[i+1]+=pre[i];
        v[i].ss -= (pre[i]*a);
        if(v[i].ss <= 0)continue;
        ll right = v[i].ff + 2*d;
        ll num = (v[i].ss)/a;
        if(v[i].ss % a)num++;
        ans += num;
        pre[i+1] += num;
        ll u = upper_bound(x.begin(),x.end(),right) - x.begin();
        pre[u] -= num;
    }
    cout << ans;
    
    return 0;
 }