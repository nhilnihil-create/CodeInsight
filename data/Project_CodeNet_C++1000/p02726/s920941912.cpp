#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> result(N, 0);

    FOR(i, 1, N) FOR(j, i + 1, N + 1) {
        int d = min(j - i, min(abs(i - X), abs(i - Y)) + min(abs(j - X), abs(j - Y)) + 1);
        ++result[d];
    }

    FOR(i, 1, N) {
        cout << result[i] << '\n';
    }
    cout << flush;

    return 0;
}
