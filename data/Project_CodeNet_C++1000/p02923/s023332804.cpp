#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N; cin >> N;
    vector<int64_t> H(N);
    for (int64_t i = 0; i < N; i++) cin >> H[i];

    int64_t res = 0, ans = -1;
    for (int64_t i = 0, j = 1; i < N - 1; i++, j++) {
        if (H.at(i) >= H.at(j)) res++;
        else {
            ans = max(ans, res);
            res = 0;
        }
    }
    ans = max(ans, res);
    cout << ans << endl;
}