#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ul = uint32_t;
using ull = uint64_t;
using l = int32_t;
using ll = int64_t;
using namespace std;

int main() {
    fastIO;
    size_t k;
    cin >> k;

    string s;
    cin >> s;

    if (s.size() <= k) {
        cout << s;

    } else {
        rep(i, k) cout << s.at(i);
        cout << "..." << endl;
    }
}