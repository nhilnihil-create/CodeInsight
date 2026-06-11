#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, S;
    cin >> N >> S;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<long long> dp(S+1);
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        vector<long long> p(S+1);
        swap(dp, p);
        for (int j = 0; j < S+1; ++j) {
            dp[j] += p[j] * 2;
            dp[j] %= 998244353;
            if (j + A[i] <= S) {
                dp[j + A[i]] += p[j];
                dp[j + A[i]] %= 998244353;
            }
        }
    }

    cout << dp[S] << endl;
    return 0;
}