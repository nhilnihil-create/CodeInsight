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

int main(){
    ll H,W;
    cin >> H >> W;
    vector<string> s(H);
    rep(i,H){
        cin >> s[i];
    }
    vector<vector<ll>> dp(H+1,vector<ll>(W+1, 1e18));
    /*rep(i,H+1){
        dp[i][0] = i-1;
    }
    rep(i,W+1){
        dp[0][i] = i-1;
    }*/
    
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    rep(i,H){
        rep(j,W){
            if(i>0){
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1] + ((s[i][j]=='#' && s[i-1][j] =='.')?1:0));
            }else{
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1] + ((s[i][j] == '#')?1:0));
            }
            if(j>0){
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j] + ((s[i][j]=='#' && s[i][j-1] == '.')?1:0));
            }else{
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j] + ((s[i][j] == '#')?1:0));
            }
            //dp[i+1][j+1] = min(dp[i+1][j], dp[i][j+1]) + ((s[i][j] == '#')?1:0);
        }
    }
    /*
    rep(i,H){
        rep(j,W){
            cout << dp[i+1][j+1] << " ";
        }
        cout << endl;
    }*/
    cout << dp[H][W] << endl;
}