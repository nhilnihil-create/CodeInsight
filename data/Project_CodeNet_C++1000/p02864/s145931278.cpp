#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L;
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>N>>K;
    ++N;
    vec h(N,0);
    rep(i,N-1) cin>>h[i+1];
    mat dp(N, vec(N - K, INF));
    //dp[i][j]:右端i番目、個数j個
    dp[0][0] = 0;
    reps(i,1,N){
        rep(j,N - K){
            ll &now = dp[i][j];
            if(j != 0){
                rep(k, i) {
                    now = min(now, dp[k][j-1] + max(0LL, h[i] - h[k]));
                }
            }
        }
    }
    /*rep(i,N){
        rep(j,N - K) cout<<dp[i][j]<<' ';
        cout<<endl;
    }*/
    ll ans = INF;
    rep(i,N){
        ans = min(ans, dp[i][N - K - 1]);
    }
    cout<<ans<<endl;
}
