#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> S(H+1);
    REP(i,0,W+1) S[0] += ".";
    REP(i,1,H+1) {
        cin >> S[i];
        S[i] = "." + S[i];
    }

    mat dp(H+1, vec(W+1, INF));
    dp[0][1] = 0;
    dp[1][0] = 0;
    REP(i,1,H+1) {
        REP(j,1,W+1) {
            ll a = dp[i-1][j], b = dp[i][j-1], m;
            if(S[i-1][j] == '.' && S[i][j] == '#') ++a;
            if(S[i][j-1] == '.' && S[i][j] == '#') ++b;;
            dp[i][j] = MIN(a,b); 
        }
    }
    PR(dp[H][W]);

    return 0;
}

/*



*/