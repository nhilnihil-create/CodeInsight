#include <iostream>
#include <cstring>

using namespace std;

const int INF = -1;

int main()
{
    int a, b;

    while (cin >> a >> b, a || b) {
        int n;
        int dp[20][20] = {0};

        dp[1][1] = 1;
        cin >> n;
        while (n--) {
            int x, y;
            cin >> x >> y;
            dp[y][x] = INF;
        }

        for (int y = 1; y <= b; y++) 
            for (int x = 1; x <= a; x++) {
                if (dp[y][x] != INF) {
                    if (y != 1 && dp[y - 1][x] != INF)
                        dp[y][x] += dp[y - 1][x];
                    if (x != 1 && dp[y][x - 1] != INF)
                        dp[y][x] += dp[y][x - 1];
                }
        }

        cout << dp[b][a] << endl;
    }

    return 0;
}