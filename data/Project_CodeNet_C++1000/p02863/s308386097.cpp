#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

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
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<ll>())
#define REV(x) reverse(ALL((x)))
#define pb push_back

int main()
{
    ll N, T;
    cin >> N >> T;
    vector<pair<ll,ll>> P(N);
    REP(i,0,N) cin >> P[i].first >> P[i].second;

    ASC(P);
    mat dp(N+1, vec(T, 0));
    ll ans = 0;
    REP(i,0,N) {
        ll t = P[i].first, v = P[i].second;
        REP(j,0,T) {
            dp[i+1][j] = MAX(dp[i+1][j],dp[i][j]);
            if(j - t >= 0) dp[i+1][j] = MAX(dp[i+1][j],dp[i][j-t]+v);
        }
        ans = MAX(ans,dp[i][T-1]+v);
    }

    PR(ans);

    return 0;
}

/*



*/