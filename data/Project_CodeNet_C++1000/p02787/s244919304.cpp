#include<iostream>
#include<vector>

using namespace std;

int main(){
    int H, N;
    int Amax = 0;
    vector<int> A, B;
    vector<vector<int>> dp;

    cin >> H >> N;
    A.resize(N + 1);
    B.resize(N + 1);
        for (int i = 1; i <= N; i++)
        {
            int a, b;
            cin >> a >> b;
            A[i] = a;
            B[i] = b;
            Amax = max(Amax, a);
        }
        dp.resize(N + 1, vector<int>(H + Amax, 100000000));
        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = 0;
        }

        for (int n = 0; n < N; n++)
        {
            for (int h = 1; h < H + Amax; h++)
            {
                if (h >= A[n + 1])
                {
                    dp[n + 1][h] = min(dp[n + 1][h - A[n + 1]] + B[n + 1], dp[n][h]);
                }
                else
                {
                    dp[n + 1][h] = min(dp[n][h], B[n + 1]);
                }
            }
        }

    int result = dp[1][H];
    for (int i = 1; i <= N; i++){
        for (int j = H; j < H + Amax; j++){
            result = min(result, dp[i][j]);
        }
    }

    cout << result << endl;
}