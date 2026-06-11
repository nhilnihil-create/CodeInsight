#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N), F(N);
    REP(i, 0, N) cin >> A[i];
    REP(i, 0, N) cin >> F[i];

    sort(ALL(A));
    sort(ALL(F), greater<>());

    ll l = -1, r = (ll)1e12, mid;
    while (r - l > 1) {
        mid = l + (r - l) / 2;
        ll cnt = K;
        REP(i, 0, N) {
            cnt -= A[i] - min(A[i], mid / F[i]);
        }
        if (cnt >= 0) r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}