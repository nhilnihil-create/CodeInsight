#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<char> w(N);

    function<void(int, int)> dfs = [&](int n, int m) {
        if (n == N) {
            REP(i, N) cout << w[i];
            cout << '\n';
            return;
        }
        REP(i, m) {
            w[n] = 'a' + i;
            dfs(n + 1, m);
        }
        w[n] = 'a' + m;
        dfs(n + 1, m + 1);
    };

    dfs(0, 0);
    cout << flush;

    return 0;
}
