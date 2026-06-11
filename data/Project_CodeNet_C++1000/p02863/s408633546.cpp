#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

int main(){
    int N, T; cin >> N >> T;
    vector<pair<ll, ll>> AB(N);
    rep(i,N) cin >> AB[i].first >> AB[i].second;
    
    sort(AB.begin(), AB.end());

    vector<vector<ll>> dp(N+1, vector<ll>(3005,0));

    ll ans = 0;
    rep(i,N){
        rep(j,T){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (j - AB[i].first >= 0) dp[i+1][j] = max(dp[i+1][j], dp[i][j-AB[i].first]+AB[i].second);
        }
        ans = max(ans, dp[i][T-1] + AB[i].second);
    }
    cout << ans << endl;
}