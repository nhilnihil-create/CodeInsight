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
#define pi M_PI
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
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<endl;}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<endl;}
template<class T> void outvp(T v){rep(i,v.size())outp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
template<class T> void outvv(T v){rep(i,v.size()){rep(j,v[i].size()){if(j)cout<<' ';cout<<v[i][j];}cout<<endl;}}
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
ll modpow(ll a,ll b){
    a%=mod;
    if(b==0)return 1;
    if(b&1)return a*modpow(a,b-1)%mod;
    ll k=modpow(a,b/2);
    return k*k%mod;
}
int main(){
    ll n,q;cin>>n>>q;
    vi v(n);
    rep(i,n)cin>>v[i];
    rep(kk,q){
        ll l,x,m;cin>>l>>x>>m;l--;
        vi p=v;
        rep(i,n){
            p[i]%=m;
            if(!p[i])p[i]=m;
        }
        x%=m;
        ll a=0,b=0;
        rep(i,n){
            if(l%n==i)a=b;
            b+=p[i];
        }
        ll sum=b*(l/n)+a+x;
        out(l-sum/m);
    }
}