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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll contr=0,contb=0,contg=0;
    rep(i,0,sz(s)){
        if(s[i]=='G')contg++;
        if(s[i]=='R')contr++;
        if(s[i]=='B')contb++;
    }
    ll ans = contr*contg*contb;
    rep(i,0,n){
        rep(j,i+1,n){
            if(s[i]==s[j])continue;
            if(j+j-i<n && s[j+j-i]!=s[i] && s[j+j-i]!=s[j])ans--;
        }
    }
    cout<<ans<<'\n';
    return 0;   
}   