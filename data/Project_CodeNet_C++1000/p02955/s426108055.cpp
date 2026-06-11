#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    int sum = 0; vector<int> A(N);
    REP(i, 0, N) {
        cin >> A[i];
        sum += A[i];
    }

    set<int> divisors;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i != 0) continue;
        divisors.insert(i);
        divisors.insert(sum / i);
    }

    int ans = 1;
    for (auto d : divisors) {
        if (d == 1) continue;
        vector<int> r(N);
        for (int i = 0; i < N; i++) r[i] = A[i] % d;
        sort(ALL(r));
        REP(i, 1, N) r[i] += r[i - 1];
        REP(i, 0, N - 1) {
            int m = r[i];
            int p = (N - 1 - i) * d - (r.back() - r[i]);
            if (m == p && m <= K) {
                ans = d;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}