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
    ll H,W;
    cin >> H >> W;
    vector<string> s(H);
    vector<vector<ll>> dp(H+1, vector<ll>(W+1, 1e18));
    rep(i,H){
        cin >> s[i];
    }
    dp[0][1] = 0;
    dp[1][0] = 0;
    rep(i,H){
        rep(j,W){
            if(j-1>=0){
                cmin(dp[i+1][j+1], dp[i+1][j] + ((s[i][j]=='#' && s[i][j-1] == '.')?1LL:0LL));
            }else{
                cmin(dp[i+1][j+1], dp[i+1][j] + ((s[i][j]=='#')?1LL:0LL));
            }
            if(i-1>=0){
                cmin(dp[i+1][j+1], dp[i][j+1] + ((s[i][j]=='#' && s[i-1][j] == '.')?1LL:0LL));
            }else{
                cmin(dp[i+1][j+1], dp[i][j+1] + ((s[i][j]=='#')?1LL:0LL));
            }
        }
    }
    cout << dp[H][W] << endl;
}