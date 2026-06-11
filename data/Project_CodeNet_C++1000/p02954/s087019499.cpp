#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> cnt(N, 0);

    rep(i, N - 1) if (S[i] == 'R' && S[i + 1] == 'L') {
        cnt[i] = 1;
        cnt[i + 1] = 1;
    }

    vector<int> sum(2, 0);
    for (int i = 0; i < N; ++i) {
        if (cnt[i] == 0 && S[i] == 'R') ++sum[i % 2];
        if (cnt[i] > 0) {
            cnt[i] += sum[i % 2];
            sum[i % 2] = 0;
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        if (cnt[i] == 0 && S[i] == 'L') ++sum[i % 2];
        if (cnt[i] > 0) {
            cnt[i] += sum[i % 2];
            sum[i % 2] = 0;
        }
    }
    rep(i, N) cout << cnt[i] << " ";
}