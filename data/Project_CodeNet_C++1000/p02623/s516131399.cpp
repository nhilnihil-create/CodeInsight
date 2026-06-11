#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 100009 /// I wanna be the wind
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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a;
    vector<ll> b;
    rep(i,0,n){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    rep(i,0,m){
        ll x;
        cin>>x;
        b.push_back(x);
    }
    rep(i,1,m){
        b[i]+=b[i-1];
    }
    ll acum=0;
    ll ans=0;
    rep(i,0,n){
        acum+=a[i];
        if(acum>k){
            continue;
        }
        ll ansact=i+1;
        ll kact= k-acum;
        ll encont=-1;
        ll ini=0,mid,fim=m-1;
        while(ini<=fim){
            mid=(fim+ini)>>1;
            if(b[mid]<=kact){
                encont=mid;
                ini=mid+1;
            }
            else fim=mid-1;
        }
        // cout<<acum<<" "<<encont<<'\n';
        if(encont!=-1)ans=max(ansact+encont+1,ans);
        else ans=max(ansact,ans);
    }
    ll kact=k;
    ll ini=0,mid,fim=m-1;
    ll encont=-1;
        while(ini<=fim){
            mid=(fim+ini)>>1;
            if(b[mid]<=kact){
                encont=mid;
                ini=mid+1;
            }
            else fim=mid-1;
        }
    if(encont!=-1)ans=max(encont+1,ans);
    cout<<ans<<"\n";
    return 0;  
}