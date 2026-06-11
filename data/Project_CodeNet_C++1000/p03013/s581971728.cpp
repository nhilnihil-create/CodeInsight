#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

const ll divider = 1000000007;

// dpで解くべし

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<int> oks(N + 1, true);
    int num;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        oks[num] = false;
    }

    vector<ll> dp(N + 1);
    dp[0] = 1;
    for (int now = 0; now < N; now++)
    {
        for (int next = now + 1; next <= min(N, now + 2); next++)
        {
            if (oks[next])
            {
                dp[next] += dp[now];
                dp[next] %= divider;
            }
        }
    }

    // for (int i = 0; i < N + 1; i++)
    // {
    //     printf("%d = %d\n", i, dp[i]);
    // }

    cout << dp[N] << endl;
}