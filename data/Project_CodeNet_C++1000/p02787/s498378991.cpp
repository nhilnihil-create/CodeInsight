#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1<<30;

template<class T> inline bool chmin(T &a, T b)
{
    if(a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for(int i=0; i<N; i++) cin >> A[i] >> B[i];

    vector<int> dp(H+1, INF); // dp[削った体力] = かかった魔力
    dp[0] = 0;
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i + A[j] < H) chmin(dp[i+A[j]], dp[i] + B[j]);
            else chmin(dp[H], dp[i] + B[j]);
        }
    }

    cout << dp[H] << endl;

    return 0;
}
