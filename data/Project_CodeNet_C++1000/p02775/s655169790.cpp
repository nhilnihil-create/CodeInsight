#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;

long int M = 1e+9+7;
int main(void){
    string n;
    cin >> n;
    vvi dp(n.size()+1, vi(2));
    int nsize = n.size();
    dp[0][0] = 0;
    dp[0][1] = 1;
    rep(i,nsize){
        int ai = n[i]-'0';
        dp[i+1][0] = min(dp[i][0]+ai, dp[i][1]+10-ai);
        dp[i+1][1] = min(dp[i][0]+ai+1, dp[i][1]+9-ai);
    }
    cout << dp[nsize][0] << endl;
    return 0;
}