#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)

void chmax(ll& a, ll b) { a = max(a, b); }
void chmin(ll& a, ll b) { a = min(a, b); }

using P = pair<int, int>;

const int MAX_N = 1e5+5;
const int INF = 1001001001;

vector<int> a, ans;
int dp[MAX_N][3];

ll modnum = 1e9+7;


int main() {
    int n; cin >> n;
    string s; cin >> s;

    vector<vector<int>> dp(n, vector<int>(n,0));
    for(int i=n-1; i >= 0; i--) for(int j=n-1; j >= 0; j--) {
        if(s[i] == s[j]) {
            dp[i][j] += 1;
            if(i < n-1 && j < n-1) {
                dp[i][j] += dp[i+1][j+1];
            }
        } else {
            dp[i][j] = 0;
        }
    }

    int ans = 0;
    rep(i, n) rep(j, n) {
        if(i >= j) continue;
        int now = min(dp[i][j], (int)(j-i));
        ans = max(ans, now);
    }

    cout << ans << endl;
    return 0;
}

