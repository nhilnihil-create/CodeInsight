#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef complex<double> xy_t;
typedef vector<lint> poly;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

const lint mod = 1e9+7;
const lint INF = mod*mod;
const int MAX =100010;

int n, K;
lint h[310], dp[2][310][310];
vector<lint> h_idx;

int main(){
    scanf("%d%d", &n, &K);
    h_idx.push_back(0);
    rep(i, n){
        scanf("%lld", &h[i]);
        h_idx.push_back(h[i]);
    }
    sort(h_idx.begin(), h_idx.end());
    h_idx.erase(unique(h_idx.begin(), h_idx.end()), h_idx.end());

    rep(i, 2)rep(j, K+1)rep(k, 310) dp[i][j][k]=INF;
    dp[0][0][0]=0;
    rep(i, n){
        rep(j, K+1)rep(k, 310)if(dp[0][j][k]<INF){
            if(j<K) chmin(dp[1][j+1][k], dp[0][j][k]);

            int idx=lower_bound(h_idx.begin(), h_idx.end(), h[i])-h_idx.begin();
            chmin(dp[1][j][idx], dp[0][j][k]+max(0LL, h[i]-h_idx[k]));
        }

        rep(j, K+1)rep(k, 310){
            swap(dp[0][j][k], dp[1][j][k]);
            dp[1][j][k]=INF;
        }
    }

    lint ans=INF;
    rep(j, K+1)rep(k, 310) chmin(ans, dp[0][j][k]);
    printf("%lld\n", ans);
}