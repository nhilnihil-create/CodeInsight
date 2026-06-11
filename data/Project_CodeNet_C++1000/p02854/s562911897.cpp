#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    rep(i, N) cin >> A[i];
    
    vector<long long> S(N + 1, 0);
    rep(i, N) S[i + 1] = S[i] + A[i];
    long long ans = 100100100100100100;
    REP(i, N) {
        long long a = S[i];
        long long b = S[N] - S[i];
        ans = min(ans, abs(a - b));
    }
    cout << ans << endl;
    return 0;
}
