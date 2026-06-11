#include "bits/stdc++.h"

using namespace std;

int main() {
    int A, B, M;
    cin >> A >> B >> M;

    vector<int> a(A), b(B);
    for (int i = 0; i < A; ++i) cin >> a[i];
    for (int i = 0; i < B; ++i) cin >> b[i];

    int mina = INT_MAX;
    for (int i = 0; i < A; ++i)
        mina = min(mina, a[i]);

    int minb = INT_MAX;
    for (int i = 0; i < B; ++i)
        minb = min(minb, b[i]);

    int ans = mina + minb;
    int x, y, c;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y >> c;
        x -= 1;
        y -= 1;
        int tmp = a[x] + b[y] - c;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
