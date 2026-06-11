#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,V,P; cin >> N >> M >> V >> P;
    vector<ll> A(N),sum(N+1,0);
    rep(i,N) cin >> A[i];
    sort(all(A)); reverse(all(A));
    rep(i,N) sum[i+1]=sum[i]+A[i];
    int ans=P;
    rep2(i,P,N){
        if (N-i+P-1>=V){
            ans+=(A[P-1]<=A[i]+M);
            continue;
        }
        ll v=(V-(N-i+P-1))*M;
        v+=sum[i]-sum[P-1];
        v-=A[P-1]*(i-P+1);
        if (v<=0) ans+=(A[P-1]<=A[i]+M);
        else ans+=(A[P-1]+(v-1)/(i-P+1)+1<=A[i]+M);
    }
    cout << ans << endl;
}