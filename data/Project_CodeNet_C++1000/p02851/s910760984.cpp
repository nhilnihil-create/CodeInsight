#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};
struct edge2{ll from,to,cost;};

int main() {
    ll N,K;
    cin >> N >> K;
    vl A(N);
    rep(i,N){
        cin >> A[i];
    }
    vP sum(N+1,{0,0});
    rep(i,N){
        sum[i+1].first=sum[i].first+A[i];
        sum[i+1].second=i+1;
    }
    rep(i,N+1){
        sum[i].first-=i;
        sum[i].first%=K;
    }
    sort(sum.begin(),sum.end());
    ll ans=0;
    rep(i,N+1){
        ll ok=N+1,ng=-1;
        P p={sum[i].first,sum[i].second+K};
        while(abs(ok-ng)>1){
            ll mid=(ok+ng)/2;
            if(sum[mid]>=p){
                ok=mid;
            }
            else{
                ng=mid;
            }
        }
        ans+=ng-i;
    }
    cout << ans << endl;
}