#include <bits/stdc++.h>
// #include <atcoder/all> // NOTE: AtCoderライブラリ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
// using namespace atcoder; // NOTE: AtCoderライブラリ
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef pair<int, int> pii;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int N; 
vl X, Y; 

int solve1() {
    int res = -1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int d = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
            res = max(d, res);
        }
    }
    return res;
}

ll solve2() {
    vl z(N), w(N);
    rep(i, N) {
        z[i] = X[i] + Y[i];
        w[i] = X[i] - Y[i];
    }
    ll zmax = -LINF, wmax = -LINF, zmin = LINF, wmin = LINF;
    rep(i, N) {
        zmax = max(zmax, z[i]);
        wmax = max(wmax, w[i]);
        zmin = min(zmin, z[i]);
        wmin = min(wmin, w[i]);
    }

    return max(zmax - zmin, wmax - wmin);
}


int main() {
    cin >> N;
    X.resize(N); Y.resize(N);
    rep(i, N) cin >> X[i] >> Y[i];

    cout << solve2() << endl;
}
