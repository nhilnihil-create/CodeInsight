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
ll fastpow(ll a, ll b){
    ll calc=1;
    for(;b>=1LL;b/=2LL){
        if((b&1LL))calc= calc*a;
        a=a*a;
    }
    return calc;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    string ans="";
    while(n>0){
        n-=1;
        ans+=char('a'+(n)%26);
        n/=26;
    }
    reverse(all(ans));
    cout<<ans<<"\n";
    return 0;  
}   