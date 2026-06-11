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
    ll h,w,k;
    cin>>h>>w>>k;
    char mat[h+2][w+2];
    rep(i,0,h){
        rep(j,0,w){
            cin>>mat[i][j];
        }
    }
    ll ans=0;
    rep(i,0,1<<(h+w)){
        // cout<<i<<'\n';
        ll total=0;
        rep(j,0,h){
            if(i&(1<<j))continue;
            rep(f,0,w){
                if(i&(1<<(f+h)))continue;
                total+=(mat[j][f]=='#');
            }
        }
        if(total==k)ans++;
    }
    cout<<ans<<"\n";
    return 0;  
}