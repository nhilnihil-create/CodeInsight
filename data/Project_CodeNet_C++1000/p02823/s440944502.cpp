#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    ll N, A, B; cin >> N >> A >> B;
    if ((B - A - 1) % 2 == 0) {
        ll ans = (1LL << 60);
        ans = min({
            ans,
            N - B + 1 + (N - (A + N - B + 1)) / 2,
            A + (B - A - 1) / 2,
        });
        cout << ans << endl;
    } else {
        cout << (B - A) / 2 << endl;
    }
    return 0;
}