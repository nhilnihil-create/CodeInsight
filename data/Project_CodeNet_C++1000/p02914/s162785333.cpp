#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef multiset<ll> S;
typedef priority_queue<ll> PQ;
typedef priority_queue<P,vector<P>,greater<P>> SPQ;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double pi=3.14159265358979323846;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}
void outvi(vi v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
void outvvi(vvi v){rep(i,v.size()){rep(j,v[i].size()){if(j)cout<<' ';cout<<v[i][j];}cout<<endl;}}
int main(){
    ll n;cin>>n;
    vi v(n);
    ll sum=0,ans=0;
    rep(i,n)cin>>v[i];
    rep(i,n)sum^=v[i];
    vector<bool> used(n,false);
    for(ll i=62;i>=0;i--){
        if(sum>>i&1){
            ans+=((ll)(1))<<i;
            continue;
        }
        ll w=inf;
        rep(j,n)if(!used[j]&&(v[j]>>i&1))w=j;
        if(w==inf){
            ll t=0;
            rep(j,n)if(v[j]>>i&1)t^=1;
            if(t)ans+=((ll)(1))<<i+1;
            continue;
        }
        used[w]=true;
        rep(j,n){
            if(j==w)continue;
            if(v[j]>>i&1)v[j]^=v[w];
        }
        ans+=((ll)(1))<<(i+1);
    }
    cout<<ans<<endl;
}