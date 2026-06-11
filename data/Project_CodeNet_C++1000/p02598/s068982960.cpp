//(UNCOMMENT WHEN SUBMITTING)
//#pragma GCC optimize("O3")

//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
// #pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

// clang-format off
#define range(i) for (int _ = 0; _ < i; _++)
#define vprnt(v) for (auto vi : v) cout << vi << " "; cout << endl;
#define fastio() ios::sync_with_stdio(false); cin.tie(0)
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace ::std;
int nxt() {int x;cin >> x;return x;}
ll nxtll() {ll x;cin >> x;return x;}
// clang-format on

int main() {
    fastio();

    int N = nxt();
    int K = nxt();

    vector<int> A(N);
    generate(all(A), nxt);

    int lo = 1, hi = 1e9, res = 1e9;
    int mid = (lo + hi) / 2;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        // cout << lo << " : " << hi << endl;
        int trials = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > mid) {
                trials += A[i] / mid + (A[i] % mid ? 1 : 0) - 1;
            }
        }
        if (trials > K) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
            res = min(res, mid);
        }
    }

    cout << res << endl;

    return 0;
}
