#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A), q(B), r(C);
    for (int i = 0; i < A; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < B; i++) {
        cin >> q[i];
    }
    for (int i = 0; i < C; i++) {
        cin >> r[i];
    }
    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());
    sort(r.begin(), r.end(), greater<int>());
    ll P[A + 1]{}, Q[B + 1]{}, R[C + 1]{};
    for (int i = 0; i < A; i++) {
        P[i + 1] = P[i] + p[i];
    }
    for (int i = 0; i < B; i++) {
        Q[i + 1] = Q[i] + q[i];
    }
    for (int i = 0; i < C; i++) {
        R[i + 1] = R[i] + r[i];
    }
    ll ans = P[X] + Q[Y];
    int id_p = X;
    int id_q = Y;
    for (int i = 1; i <= min(C, X + Y); i++) {
        if (id_p == 0 && id_q == 0) {
            ans = max(ans, R[min(X + Y, C)]);
            break;
        }
        if (id_p == 0) {
            id_q--;
        } else if (id_q == 0) {
            id_p--;
        } else if (P[id_p - 1] + Q[id_q] < P[id_p] + Q[id_q - 1]) {
            id_q--;
        } else {
            id_p--;
        }
        ans = max(ans, R[i] + P[id_p] + Q[id_q]);
    }
    cout << ans << "\n";
    return 0;
}