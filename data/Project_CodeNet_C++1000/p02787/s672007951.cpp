#include <bits/stdc++.h>
using namespace std;

// E - Crested Ibis vs Monster
// DP計画法を利用する
struct Atack {
    int power;
    int magic;
};
int main() {
    int H, N;
    cin >> H >> N;
    vector<Atack> atack(N);
    int A, B;
    for (int i = 0; i < N; i++) {
        cin >> atack[i].power;
        cin >> atack[i].magic;
    }

    long dp[H+1];
    for (int i = 1; i <= H; i++) {
        dp[i] = 1e13;
        for (int j = 0; j < N; j++) {
            if (atack[j].power >= i) {
                dp[i] = min((long)atack[j].magic, dp[i]);
            } else {
                dp[i] = min(dp[i - atack[j].power]  + atack[j].magic, dp[i]);
            }
        }
    }
    cout << dp[H];
}
