#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N, P; string S; cin >> N >> P >> S;

    ll ans = 0;
    if (P == 2 || P == 5) {
        REP(i, 0, N) if ((S[N - i - 1] - '0') % P == 0) ans += N - i;
    } else {
        vector<ll> mods(P, 0);

        ll cur = 0, coef = 1;
        mods[cur]++;
        REP(i, 0, N) {
            cur = (cur + coef * (S[N - i - 1] - '0') % P) % P;
            coef = coef * 10 % P;
            mods[cur]++;
        }

        REP(i, 0, P) {
            ans += mods[i] * (mods[i] - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}