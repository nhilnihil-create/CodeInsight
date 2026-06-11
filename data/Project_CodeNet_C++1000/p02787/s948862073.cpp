#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = (int)(n); i >= 0; i--)
#define FOR(i, m, n) for (int i = (m); i < (int)(n); i++)
#define INF 100000000

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}

int main()
{
    ll H, N;
    cin >> H >> N;
    vector<ll> A(N), B(N);

    REP(i, N)
    cin >> A[i] >> B[i];

    ll dp[H + 1];
    REP(i, H + 1)
    {
        dp[i] = INF;
    }

    dp[0] = 0;

    REP(i, N)
    {
        REP(j, H)
        {
            chmin(dp[min(j + A[i], H)], dp[j] + B[i]);
        }
    }

    cout << dp[H] << endl;
}