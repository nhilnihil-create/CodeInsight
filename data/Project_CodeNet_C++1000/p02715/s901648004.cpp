#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 100009 /// Still trying to be normal
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
ll ans[maxn];
ll mult(ll a,ll b){
    return a*b%MOD;
}
ll fastpow(ll a, ll b){
    ll calc=1;
    for(;b>=1LL;b/=2LL){
        if((b&1LL))calc=mult(calc,a);
        a=mult(a,a);
    }
    return calc;
}
ll soma(ll a,ll b){
    if(a+b>MOD)return a+b-MOD;
    else return a+b;
}
ll subt(ll a,ll b){
    if(a-b<0)return a-b+MOD;
    else return a-b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    per(i,k+1,1){
        ans[i]=fastpow((k/i),n);
        for(int j=2*i;j<=k;j+=i){
            ans[i]=subt(ans[i],ans[j]);
        }
    }
    ll res=0;
    rep(i,1,k+1)res=soma(res,mult(ans[i],i));
    cout<<res<<'\n';
    return 0;   
}   