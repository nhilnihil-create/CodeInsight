#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end(), greater<long long>());
    return ret;
}
 
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    int sum = 0;
    REP(i, N) {
        cin >> A.at(i);
        sum += A[i];
    }
    auto d = divisor(sum);  // 合計値の約数
 
    vector<int> r(N);
    REP(i, d.size()) {
        REP(j, N) { r[j] = A[j] % d[i]; }
        sort(ALL(r));
        vector<int> L(N + 1), R(N + 1);
        L[0] = 0;
        R[N] = 0;
        REP(j, N) { L[j + 1] += r[j] + L[j]; }
        for (int j = N - 1; j >= 0; j--) {
            R[j] += (d[i] - r[j]) + R[j + 1];
        }
        REP(j, N + 1) {
            if (L[j] == R[j] && L[j] <= K) {
                cout << d[i] << endl;
                return 0;
            }
        }
    }
 
    cout << N << endl;
    return 0;
}
 