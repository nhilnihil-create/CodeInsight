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
    string S;
    cin >> S;
    ll N = SZ(S);
    S = "0" + S;

    mat dp(N+1, vec(2, 0));
    dp[0][1] = 1;
    REP(i,1,N+1) {
        ll n = S[i] - '0';
        dp[i][0] = MIN(dp[i-1][0]+n,dp[i-1][1]+10-n);
        dp[i][1] = MIN(dp[i-1][0]+n+1,dp[i-1][1]+9-n);
    }
    PR(dp[N][0]);

    return 0;
}

/*



*/