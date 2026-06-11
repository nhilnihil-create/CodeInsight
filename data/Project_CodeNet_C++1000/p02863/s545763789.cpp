#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> Plp;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N,T;
    cin >> N >> T;
    vector<ll> A(N), B(N);
    vector<vector<ll>> dp1(3001, vector<ll>(3001));
    vector<vector<ll>> dp2(3001, vector<ll>(3001));
    rep(i,N){
        cin >> A[i] >> B[i];
    }
    rep(i,N){
        rep(j,T){
            if(j-A[i] >= 0){
                cmax(dp1[i+1][j], dp1[i][j-A[i]] + B[i]);
            }
            cmax(dp1[i+1][j], dp1[i][j]);
        }
    }
    for(ll i=N;i>0;i--){
        rep(j,T){
            if(j-A[i-1] >= 0){
                cmax(dp2[i-1][j], dp2[i][j-A[i-1]] + B[i-1]);
            }
            cmax(dp2[i-1][j], dp2[i][j]);
        }
    }
    ll ans = 0;
    //cout << dp1[0][T-1] << " " << dp1[1][T-1] << " " << dp1[2][T-1] << " " << dp1[3][T-1] << endl;
    //cout << dp2[0][T-1] << " " << dp2[1][T-1] << " " << dp2[2][T-1] << " " << dp2[3][T-1] << endl;
    REP(i,0,N){
        rep(j,T){
            cmax(ans, dp1[i][j] + dp2[i+1][T-1-j] + B[i]);
        }
    }
    cout << ans << endl;
}