#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;

int N, M, Q;
vector<int> a, b, c, d, A;

int rec(int n) {
    if (n == N) {
        int res = 0;
        rep(i, Q) {
            if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
        }
        return res;
    }
    if (n == 0) {
        int res = 0;
        rep(i, M) {
            A[0] = i;
            res = max(res, rec(n + 1));
        }
        return res;
    }
    int res = 0;
    rep(i, M) {
        if (A[n - 1] <= i) {
            A[n] = i;
            res = max(res, rec(n + 1));
        }
    }
    return res;
}

int main() {
    cin >> N >> M >> Q;
    a = b = c = d = vector<int>(Q, 0);
    A = vector<int>(N, 0);
    rep(i, Q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i]; --b[i];
    }
    cout << rec(0) << "\n";
    return 0;
}
