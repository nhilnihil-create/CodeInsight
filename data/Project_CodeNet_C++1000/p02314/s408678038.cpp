#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> kind(M);
    for (int i = 0; i < M; ++i) cin >> kind[i];
    sort(kind.begin(), kind.end());

    vector<int> dp(N+1, N); dp[0] = 0;
    for (int i = 0; i < M; ++i)
        for (int j = kind[i]; j <= N; ++j)
            dp[j] = min(dp[j], dp[j - kind[i]] + 1);

    cout << dp[N] << endl;

    return 0;
}