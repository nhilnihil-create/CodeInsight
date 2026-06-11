#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    vector<vector<ll>> c(M);
    vector<vector<ll>> dp(5000,vector<ll>(1001,1e18));
    dp[0][0] = 0;
    ll C;
    rep(i,M){
        cin >> a[i] >> b[i];
        rep(j,b[i]){
            cin >> C;
            c[i].push_back(--C);
        }
    }
    //cout << "bb" <<endl;
    rep(i,M){
        ll k=0;
        rep(j,b[i]){
            k = k | (1LL << c[i][j]);
        }
        rep(j,(1LL << N)){
            dp[j][i+1] = dp[j][i];
        }
        rep(j,(1LL << N)){
            dp[(j|k)][i+1] = min(dp[j|k][i+1], dp[j][i] + a[i]);
        }
    }
    if(dp[((1LL << N) - 1LL)][M] == 1e18){
        cout << -1 << endl;
        return 0;
    }
    cout << dp[((1LL << N) - 1LL)][M] << endl;
}