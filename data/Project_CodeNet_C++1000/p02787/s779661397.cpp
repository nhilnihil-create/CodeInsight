#include <iostream>
#include <vector>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;

int main() {
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];
    
    vector<long long> dp(H+1, INF);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= H; ++j) {
            chmin(dp[min(j+A[i], H)], dp[j] + B[i]);
        }
    }
    cout << dp[H] << endl;
}