#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    Int N, M, V, P;
    cin >> N >> M >> V >> P;
    vector<Int> A(N);
    for (Int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(all(A));
    A.push_back(INF);
    Int ok = N - 1;
    Int ng = -1;
    while (abs(ok - ng) > 1) {
        Int mid = (ok + ng) / 2;
        Int index = upper_bound(all(A), A[mid] + M) - A.begin();
        Int k = N - index + 1;
        Int v = V;
        if (mid < v - 1) {
            v -= mid + 1;
            if (k - 1 < v) {
                v -= k - 1;
                Int x = v * M;
                for (Int i = mid + 1; i < index; i++) {
                    x -= A[mid] + M - A[i];
                }
                if (x > 0) {
                    Int cnt = 0;
                    for (Int i = index - 1; i > mid; i--) {
                        x -= A[i] - A[mid];
                        cnt++;
                        if (x <= 0) break;
                    }
                    k += cnt;
                }
            }
        }
        if (k <= P) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    dump(N - ok);
    return 0;
}