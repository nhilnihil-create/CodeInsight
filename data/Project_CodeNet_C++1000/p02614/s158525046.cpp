#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
#define pll pair<ll,ll>
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

char x[10][10],y[10][10];
int main(){
    ll h,w,k,ans=0;;
    cin>>h>>w>>k;
    rep(i,0,h){
        rep(j,0,w){
            cin>>x[i][j];
            y[i][j]=x[i][j];
        }
    }
    for(int mask = 0; mask < (1 << h); mask++){
        
        for(int mask2 = 0; mask2 < (1 << w); mask2++){
            rep(i,0,h){
             rep(j,0,w){
                y[i][j]=x[i][j];
             }
             }
            rep(i,0,h)if(mask&(1<<i))rep(j,0,w)y[i][j]='a';
            rep(i,0,w)if(mask2&(1<<i))rep(j,0,h)y[j][i]='a';
            ll tmp=0;
            rep(i,0,h){
                rep(j,0,w){
                    if(y[i][j]=='#')tmp++;
                }
            }
            if(tmp==k)ans++;
    }
    }
    cout<<ans;
}


