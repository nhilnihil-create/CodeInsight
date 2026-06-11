#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;

    vector<int> w(N), z(N);
    REP(i, 0, N) {
        int x, y; cin >> x >> y;
        w[i] = x + y;
        z[i] = x - y;
    }

    sort(ALL(w));
    sort(ALL(z));

    cout << max(w.back() - w[0], z.back() - z[0]) << endl;
    return 0;
}