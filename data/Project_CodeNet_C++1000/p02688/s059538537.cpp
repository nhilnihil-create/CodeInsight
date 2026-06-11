#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N, K, d, a, ans = 0;
    cin >> N >> K;
    vector<int> A(N, 1);
    for(int i = 0; i < K; ++i) {
        cin >> d;
        for(int j = 0; j < d; ++j) {
            cin >> a;
            A[a-1] -= 1;
        }
    }

    rep(i, N) {
        if (A[i] > 0) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
