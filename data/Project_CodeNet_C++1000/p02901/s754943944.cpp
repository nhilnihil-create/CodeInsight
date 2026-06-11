#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M), bitKey(M);
    REP(i, M)
    {
        cin >> a[i] >> b[i];
        bitKey[i] = 0;
        REP(j, b[i])
        {
            ll c;
            cin >> c;
            c--;
            bitKey[i] |= 1 << c;
        }
    }

    ll dp[M + 1][1 << N];
    ll INF = 1e12;
    REP(i, M + 1)
    {
        REP(j, 1 << N)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    for (ll i = 1; i <= M; ++i)
    {
        REP(j, 1 << N)
        {
            ll bitNow = j | bitKey[i - 1];
            dp[i][bitNow] = min(dp[i][bitNow], dp[i - 1][j] + a[i - 1]);
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);
        }
    }
    ll ans = dp[M][(1 << N) - 1] == INF ? -1 : dp[M][(1 << N) - 1];

    cout << ans << endl;
}