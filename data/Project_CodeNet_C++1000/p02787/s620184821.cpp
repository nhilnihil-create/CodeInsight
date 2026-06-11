#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const ll INF = 1LL << 60;

int main(){
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    vector<vector<ll>> dp(n+1, vector<ll>(h+1, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= h; j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            int col = min(j+a[i-1], h);
            dp[i][col] = min(dp[i][col], dp[i][j] + b[i-1]);
        }
    }
    cout << dp[n][h] << endl;
    return 0;
}