#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> D(N);
    REP(i, 0, N) cin >> D[i];

    ll ans = 0;
    REP(i, 0, N) {
        REP(j, i + 1, N) {
            ans += D[i] * D[j];
        }
    }
    cout << ans << endl;
    return 0;
}