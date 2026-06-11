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
    ll ans=0;
    cin>>n;
    string s;
    cin>>s;
    ll pre[n+2][4];
    memset(pre,0,sizeof pre);
    rep(i,0,sz(s)){
        if(s[i]=='R'){
            pre[i+1][1]++;
        }
        if(s[i]=='G'){
            pre[i+1][2]++;
        }
        if(s[i]=='B'){
            pre[i+1][3]++;
        }
        rep(j,1,4){
            pre[i+1][j]+=pre[i][j];
        }
    }
    // cout<<pre[n+1][3]<<endl;
    rep(i,0,n){
        rep(j,i+1,n){
            if(s[i]==s[j])continue;
            if(j+j-i<n && s[j+j-i]!=s[i] && s[j+j-i]!=s[j])ans--;
            bool is1=0,is2=0,is3=0;
            if(s[i]=='R' || s[j]=='R') is1 = 1;
            if(s[i]=='G' || s[j]=='G') is2 = 1;
            if(s[i]=='B' || s[j]=='B') is3 = 1;
            if(!is1){
                ans+=pre[n][1]-pre[j+1][1];
            }
            if(!is2){
                ans+=pre[n][2]-pre[j+1][2];
            }
            if(!is3){
                ans+=pre[n][3]-pre[j+1][3];
            }
        }
    }
    cout<<ans<<'\n';
    return 0;   
}   