#include <iostream>
#include <cstring>


using namespace std;

typedef long long ll;
const int MAX = 1e6;
char str[MAX];
int dp[MAX + 1][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;
    int len = strlen(str);
    for (int j = 0; j < len; ++j) {
        str[j] -= '0';
    }

    dp[0][0] = str[0];
    dp[0][1] = 10 - str[0] + 1;
    for (int i = 1; i < len; ++i) {
        dp[i][0] = min(dp[i - 1][1] + str[i], dp[i - 1][0] + str[i]);
        dp[i][1] = min(dp[i - 1][1] - 1 + 10 - str[i], dp[i - 1][0] + 10 - str[i] + 1);
    }

    cout << min(dp[len - 1][0], dp[len - 1][1]);
    return 0;
}