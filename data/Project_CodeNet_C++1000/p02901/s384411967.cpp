#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

ll dp[1110][5000];

int main()
{
    int N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M), c(M, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> a[i] >> b[i];
        for (int j = 0; j < b[i]; j++)
        {
            int t;
            cin >> t;
            --t;
            c[i] += (1 << t);
        }
    }

    for (int i = 0; i < 1100; i++)
    {
        for (int j = 0; j < 5000; j++)
        {
            dp[i][j] = LINF;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            // i番目の鍵を使わない場合
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

            // i番目の鍵を使う場合(jの状態から鍵を使った結果)
            int nj = j | c[i];
            dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + a[i]);
        }
    }
    cout << (dp[M][(1 << N) - 1] < INF ? dp[M][(1 << N) - 1] : -1) << endl;
    return 0;
}
