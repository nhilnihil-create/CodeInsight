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
    ll N;
    cin >> N;
    vector<pair<ll,ll>> A(N);
    REP(i,0,N) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }
    ASC(A);
    A.emplace_back(0, 0);
    REV(A);

    mat dp(N+1, vec(N+1, 0));
    REP(k,0,N) {
        REP(i,0,k+1) {
            ll j = k - i;
            ll p = A[k+1].second;
            ll a = A[k+1].first;
            dp[i+1][j] = MAX(dp[i+1][j],dp[i][j]+a*abs(p-i-1));
            dp[i][j+1] = MAX(dp[i][j+1],dp[i][j]+a*abs(p-N+j));
        }
    }

    ll ans = 0;
    REP(i,0,N+1) ans = MAX(ans,dp[i][N-i]);
    PR(ans);

    return 0;
}

/*



*/