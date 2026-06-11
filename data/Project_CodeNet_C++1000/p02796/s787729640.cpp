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

int main() {
    int N; cin >> N;
    vector<int> X(N), L(N); rep(i, N) cin >> X[i] >> L[i];
    
    vector<pii> y(N);
    rep(i, N) {
        y[i] = make_pair(X[i] - L[i], X[i] + L[i]);
    }

    sort(y.begin(), y.end(), [](const pii &a, const pii &b) {
        return a.second < b.second;
    });

    int prev = -INF;
    int cnt = 0;
    for (auto a : y) {
        int a1 = a.first;
        int a2 = a.second;

        if (prev <= a1) {
            prev = a2;
            cnt++;
        }
    }

    cout << cnt << endl;
}
