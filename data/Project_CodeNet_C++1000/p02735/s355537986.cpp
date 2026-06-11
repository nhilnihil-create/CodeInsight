#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int INF = 1001001001;

int dp[105][105];

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    rep(i, h) rep(j, w) dp[i][j] = INF;
    if (s[0][0]=='#') dp[0][0] = 1;
    else dp[0][0] = 0;
    rep(i, h) rep(j, w) {
        if (i==0 && j==0) continue;
        if (j>0) {
            int now = dp[i][j-1];
            if (s[i][j-1]=='.' && s[i][j]=='#') now += 1;
            chmin(dp[i][j], now);
        }
        if (i>0) {
            int now = dp[i-1][j];
            if (s[i-1][j]=='.' && s[i][j]=='#') now += 1;
            chmin(dp[i][j], now);
        }
    }
    int ans = dp[h-1][w-1];
    
    cout << ans << endl;
    return 0;
}
