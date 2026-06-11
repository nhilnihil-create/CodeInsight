#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for(auto &e : A) cin >> e;
    vector<int64_t> S(N + 1);
    for(int i = 0; i < N; ++i) S[i + 1] = S[i] + A[i];
    for(int i = 1; i <= N; ++i) S[i] = (S[i] - i) % K;
    map<int, int> ma;
    int64_t ans = 0;
    for(int i = 0; i <= N; ++i) {
        ans += ma[S[i]];
        ma[S[i]]++;
        if(i - K + 1 >= 0) ma[S[i - K + 1]]--;
    }
    cout << ans << '\n';
    return 0;
}
