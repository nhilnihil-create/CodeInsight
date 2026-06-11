#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
int main() {
    int n, K; cin >> n >> K;
    int h[n]; for (int i = 0; i < n; i++) cin >> h[i];
    set<int> s; for (int i = 0; i < n; i++) s.insert(h[i]);
    s.insert(0);
    vector<int> H(s.begin(), s.end());
    long long dp[2][H.size()][K+1];
    int cur = 0, prev = 1;
    const long long INF = 1LL<<60;
    for (int j = 0; j < H.size(); j++)
        for (int k = 0; k <= K; k++) {
            dp[cur][j][k] = dp[prev][j][k] = INF;
        }
    dp[prev][0][0] = 0;
    for (int i = 0; i < n; i++) {
        long long R[H.size()][K+1], L[H.size()][K+1];
        for (int j = H.size() - 1; j >= 0; j--) {
            for (int k = 0; k <= K; k++)
                if (j == H.size()-1) R[j][k] = dp[prev][j][k];
                else R[j][k] = min(R[j+1][k], dp[prev][j][k]);
        }
        for (int j = 0; j < H.size(); j++) {
            for (int k = 0; k <= K; k++)
                if (j == 0) L[j][k] = INF;
                else L[j][k] = min(L[j-1][k], dp[prev][j-1][k] - H[j-1]);
        }
        for (int j = 0; j < H.size(); j++) {
            int d = (H[j] != h[i]);
            for (int k = 0; k <= K; k++) {
                dp[cur][j][k] = k < d ? INF : min(R[j][k-d], L[j][k-d] + H[j]);
            }
        }
        swap(cur, prev);
    }
    long long ans = INF;
    for (int i = 0; i < H.size(); i++)
        ans = min(ans, *min_element(dp[prev][i], dp[prev][i] + K + 1));
    cout << ans << endl;
}
