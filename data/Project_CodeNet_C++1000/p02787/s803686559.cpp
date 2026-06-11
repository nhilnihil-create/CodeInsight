#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;
const double PI = 3.14159265358979323846;

int main()
{

    int H, N;
    cin >> H >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++)
    {

        cin >> A[i] >> B[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(H + 1, 1000000000));

    for (int i = 0; i <= min(A[0],H); i++)
    {
        dp[1][i] = B[0];
    }

    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i < N; i++)
    {

        for (int j = 1; j < H + 1; j++)
        {

            if (j >= A[i])
            {
                dp[i + 1][j] = min(dp[i + 1][j - A[i]] + B[i], dp[i][j]);
            }
            else
            {

                dp[i + 1][j] = min(dp[i][j], dp[i + 1][0] + B[i]);
            }
        }
    }

    cout << dp[N][H] << endl;;

    return 0;
}