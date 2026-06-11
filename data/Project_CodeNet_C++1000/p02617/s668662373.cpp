#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

using ll = long long;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    ll result = 0;
    FOR(i, 1, N + 1) {
        result += (ll) i * (N - i + 1);
    }
    REP(_, N - 1) {
        int u, v;
        cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        result -= (ll) u * (N - v + 1);
    }
    cout << result << endl;

    return 0;
}
