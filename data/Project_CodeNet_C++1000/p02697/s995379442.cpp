#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair< int, int >;

int main() {
    int N, M;
    cin >> N >> M;

    vector< P > res;
    if (N % 2 != 0) {
        for (int l = 1, r = N - 1; l < r; ++l, --r) {
            res.emplace_back(P(l, r));
        }
    } else {
        bool flag = false;
        for (int l = 1, r = N - 1; l < r; ++l, --r) {
            if (!flag && r - l <= N / 2) {
                --r;
                flag = true;
            }
            res.emplace_back(P(l, r));
        }
    }

    rep(i, M) { printf("%d %d\n", res[i].first, res[i].second); }
}