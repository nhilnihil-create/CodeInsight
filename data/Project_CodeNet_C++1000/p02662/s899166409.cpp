#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <list>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define debug(x) (cout << # x ": " << x << endl)
#define ll long long int
#define repeat(n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define llcast static_cast<long long int>

#define PRIME (998244353)
#define MAX_SIZE (3001)

int dp[MAX_SIZE][MAX_SIZE];

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> v;

    repeat(n) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    dp[0][0] = 1;

    repeat(n) {
        for (int j = 0; j <= s; ++j) {
            dp[i + 1][j] = (2ll * dp[i][j] + dp[i + 1][j]) % PRIME;
            int y = v[i] + j;
            if (y <= s) {
                dp[i + 1][y] = (llcast(dp[i + 1][y]) + dp[i][j]) % PRIME;
            }
        }
    }

    cout << dp[n][s];

    return 0;
}