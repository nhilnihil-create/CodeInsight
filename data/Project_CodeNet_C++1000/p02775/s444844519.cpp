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
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    string S;
    cin >> S;
    ll N = S.size();
    ll ans = 0;
    reverse(S.begin(), S.end());
    S += '0';
    N++;
    vector<vector<ll>> dp(N+1, vector<ll>(2,1e18));
    dp[0][0] = 0;
    rep(i,N)rep(j,2){
        ll d = S[i] - '0';
        ll x = d + j;
        if(x < 10)cmin(dp[i+1][0], dp[i][j] + x);
        if(x > 0)cmin(dp[i+1][1], dp[i][j] + 10-x);
    }
    /*
    rep(i,N+1){
        cout << dp[i][0] << " ";
    }
    cout << endl;
    rep(i,N+1){
        cout << dp[i][1] << " ";
    }
    cout << endl;*/

    cout << dp[N][0] << endl;
}