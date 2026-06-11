#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
    int N, K;

    cin >> N >> K;
    vector<int>A(N);
    rep (i, N) {
        cin >> A[i];
    }

    rep (k, K) {
        vector<int>B(N+1);
        rep (i, N) {
            int s = max(0, i-A[i]);
            int l = min(i + A[i] + 1, N);
            B[s]++; B[l]--;
        }
        rep (i, N) B[i+1] += B[i];
        B.pop_back();
        if (A == B) break;
        A = B;
    }
    rep (i, N) {
        cout << A[i];
        if (i != N) cout << ' ';
    }
    cout << endl;
}
