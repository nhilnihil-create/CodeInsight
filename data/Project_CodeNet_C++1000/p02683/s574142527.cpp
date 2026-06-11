#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int N, M, X;

int main()
{
    cin >> N >> M >> X;
    int a[14][14];
    int c[14];
    ll ans;
    rep(i, 0, N)
    {
        cin >> c[i];
        rep(j, 0, M)
        {
            cin >> a[i][j];
        }
    }

    bool flg = true;
    ll min = LLONG_MAX;
    for (int bits = 0; bits < (1 << N); bits++)
    {
        vector<int> sum(M, 0);
        ans = 0;
        for (int i = 0; i < N; i++)
        {
            if (bits & (1 << i))
            {
                for (int j = 0; j < M; j++)
                {
                    sum[j] += a[i][j];
                }
                ans += c[i];
            }
        }
        // cout << ans << endl;
        flg = true;
        rep(j, 0, M)
        {
            if (sum[j] < X)
            {
                flg = false;
            }
        }
        if (flg)
        {
            if (ans < min)
            {
                // cout << min << endl;
                min = ans;
            }
        }
    }

    if (min == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min << endl;
    }
    return 0;
}
