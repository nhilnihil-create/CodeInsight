#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
using ui64 = uint_fast64_t;
#define REP(i, n) for (i64 (i) = 0; (i) < (n); ++(i))
#define FOR(i, a, b) for (i64 (i) = (a); (i) < (b); ++(i))

signed main() {

    int N;
    cin >> N;

    vector<i64> A(N), C(N + 1, 0), D(N + 1, 0), F(N, 0);
    vector<i64> D_acc(N + 2, 0), kD_acc(N + 2, 0);
    
    REP(i, N) cin >> A[i];
    REP(i, N) C[A[i]]++;
    REP(i, N + 1) D[C[i]]++;
    REP(i, N + 1) D_acc[i + 1] = D_acc[i] + D[i];
    REP(i, N + 1) kD_acc[i + 1] = kD_acc[i] + i * D[i];
    FOR(i, 1, N + 1) F[i - 1] = (kD_acc[i + 1] + i * (D_acc[N + 1] - D_acc[i + 1])) / i;
    REP(i, N) F[i] = -F[i];
    FOR(k, 1, N + 1) {
        auto itr = upper_bound(F.begin(), F.end(), -k);
        cout << distance(F.begin(), itr) << endl;
    }

    return 0;
    REP(i, N + 1) cerr << C[i] << " \n"[i == N];
    REP(i, N + 1) cerr << D[i] << " \n"[i == N];
    REP(i, N + 2) cerr << D_acc[i] << " \n"[i == N + 1];
    REP(i, N + 2) cerr << kD_acc[i] << " \n"[i == N + 1];
    REP(i, N) cerr << F[i] << " \n"[i == N - 1];

}
