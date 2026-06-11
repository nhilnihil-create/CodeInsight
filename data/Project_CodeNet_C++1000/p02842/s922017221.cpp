#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    bool ok = false;
    rep(m, 50000) {
        if (m * 108 / 100 == N) {
            ok = true;
            cout << m << endl;
            break;
        }
    }

    if (!ok) cout << ":(" << endl;

    return 0;
}