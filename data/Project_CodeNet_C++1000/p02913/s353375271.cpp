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

int dp[5005][5005];

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;

    for (int i=n-1; i>=0; i--) {
        for (int j=n-1; j>=0; j--) {
            if (s[i]==s[j]) {
                dp[i][j] = dp[i+1][j+1] + 1;
            }
        }
    }
    rep(i, n) rep(j, n) {
        if (i>=j) continue;
        int v = dp[i][j];
        if (v<=j-i) ans = max(ans, v);
    }
    
    cout << ans << endl;
    return 0;
}
