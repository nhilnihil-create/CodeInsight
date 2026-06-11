// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100][16384];

int main(int argc, char **argv)
{
        int N, W;
        cin >> N >> W;
        vector<int> v(N), w(N);
        for (int i = 0; i < N; i++)
                cin >> v[i] >> w[i];
        for (int i = 0; i < N; i++) {
                for (int j = 0; j <= W; j++) {
                        if (!i) {
                                dp[i][j] = w[i] <= j ? v[i] : 0;
                        }
                        else if (j < w[i]) {
                                dp[i][j] = dp[i-1][j];
                        }
                        else {
                                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
                        }
                }
        }
        cout << dp[N-1][W] << endl;
        return 0;
}