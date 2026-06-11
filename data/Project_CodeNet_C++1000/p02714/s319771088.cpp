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
    vector<ll> posr,posg,posb;
    rep(i,0,sz(s)){
        if(s[i]=='R'){
            posr.push_back(i);
        }
        if(s[i]=='G'){
            posg.push_back(i);
        }
        if(s[i]=='B'){
            posb.push_back(i);
        }
    }
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
    rep(i,0,sz(posr)){  /// RG
        rep(j,0,sz(posg)){
            auto i2 = posr[i];
            auto j2 = posg[j];
            if(j2<i2)continue;
            ans+=pre[n][3]-pre[j2+1][3];
            // cout<<ans<<endl;
            if(((j2+(j2-i2)<n) && s[j2+(j2-i2)]=='B'))ans--;
        }
    }
    // cout<<ans<<endl;
    rep(i,0,sz(posr)){ /// RB
        rep(j,0,sz(posb)){
            auto i2 = posr[i];
            auto j2 = posb[j];
            if(j2<i2)continue;
            ans+=pre[n][2]-pre[j2+1][2];
            if(((j2+(j2-i2)<n) && s[j2+(j2-i2)]=='G'))ans--;
        }
    }


    rep(i,0,sz(posb)){/// BG
        rep(j,0,sz(posg)){
            auto i2 = posb[i];
            auto j2 = posg[j];
            if(j2<i2)continue;
            ans+=pre[n][1]-pre[j2+1][1];
            if(((j2+(j2-i2)<n) && s[j2+(j2-i2)]=='R'))ans--;
        }
    }

    rep(i,0,sz(posb)){/// BR
        rep(j,0,sz(posr)){
            auto i2 = posb[i];
            auto j2 = posr[j];
            if(j2<i2)continue;
            ans+=pre[n][2]-pre[j2+1][2];
            if(((j2+(j2-i2)<n) && s[j2+(j2-i2)]=='G'))ans--;
        }
    }

    rep(i,0,sz(posg)){/// GB
        rep(j,0,sz(posb)){
            auto i2 = posg[i];
            auto j2 = posb[j];
            if(j2<i2)continue;
            ans+=pre[n][1]-pre[j2+1][1];
            if(((j2+(j2-i2)<n) && s[j2+(j2-i2)]=='R'))ans--;
        }
    }

    rep(i,0,sz(posg)){/// GR
        rep(j,0,sz(posr)){
            auto i2 = posg[i];
            auto j2 = posr[j];
            if(j2<i2)continue;
            ans+=pre[n][3]-pre[j2+1][3];
            if(((j2+(j2-i2)<n) && s[j2+(j2-i2)]=='B'))ans--;
        }   
    }
    cout<<ans<<'\n';
    return 0;   
}   