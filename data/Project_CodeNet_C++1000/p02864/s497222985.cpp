#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n,k;
ll h[310],dp[310][310][310];

void solve(){
    cin >> n >> k;
    rep(i,n){
        cin >> h[i+1];
    }
    rep(i,n+1){
        rep(j,n+1){
            rep(l,k+1){
                dp[i][j][l]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    rep(i,n){
        rep(l,min(i+1,k)){
            rep(j,i+1){
                dp[i+1][j][l+1]=min(dp[i+1][i+1][l+1],dp[i][j][l]);
            }
        }
        rep(l,min(i+1,k+1)){
            rep(j,i+1){
                dp[i+1][i+1][l]=min(dp[i+1][i+1][l],dp[i][j][l]+max(h[i+1]-h[j],0ll));
            }
        }
    }
    ll ans=INF;
    rep(j,n+1){
        rep(l,k+1){
            ans=min(ans,dp[n][j][l]);
        }
    }
    rep(i,n+1){
        rep(j,n+1){
            rep(l,k+1){
                if (dp[i][j][l]==INF) continue;
                //cout << i << " " << j << " " << l << " " << dp[i][j][l] << endl;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}