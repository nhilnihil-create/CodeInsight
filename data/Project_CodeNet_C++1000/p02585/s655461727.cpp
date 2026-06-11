#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 200009 /// I wanna be the wind
#define MOD 1000000007
#define F first
#define S second
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define per(i, b, a) for(ll i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
using namespace std;
const ll INF = 1e17 + 9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    ll pe[n+2],c[n+2];
    rep(i,0,n)cin>>pe[i],pe[i]--;
    rep(i,0,n)cin>>c[i];
    ll ans = -INF;
    rep(i,0,n){
        ll tamcic=0;
        ll vcic=0;
        ll v = i;
        ll k2=k;
        while(true){
            tamcic++,vcic+=c[v];
            v = pe[v];
            if(v==i)break;
        }
        ll valact=0;
        ll cont2=0;
        while(true){
            cont2++;
            valact+=c[v];
            k2--;
            if(k2<0)break;
            ans = max(ans,valact+((k-cont2)/tamcic)*max(0LL,vcic));
            v = pe[v];
            if(v==i)break;
        }
    }
    cout<<ans<<'\n';
    return 0;  
}   