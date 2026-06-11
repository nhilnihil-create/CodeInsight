#include <bits/stdc++.h>
using namespace std;
int H, N;

const int MAX_H = 10000;
const int MAX_N = 1000;
const int MAX_A = 10000;
const int MAX_B = 10000;

int A[MAX_N], B[MAX_N];

long long dp[MAX_N + 2][MAX_H + 1];

void input() { 
    cin >> H >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
}

void initialize() {
    for(int i = 0; i <= N+1; i++) {
        for(int j = 1; j <= H; j++) {
            dp[i][j] = 100000001;
        }
    }
}

int main() {
    input();
    initialize();

    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= H; j++) {
            dp[i+1][j] = min(dp[i][j], dp[i+1][j-A[i]]+B[i]);
        }
    }
    cout << dp[N][H] << endl;

    return 0;
}