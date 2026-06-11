#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int takahashi = 1;
    while (1) {
        if (takahashi) {
            c -= b;
            if (c <= 0) {
                cout << "Yes" << endl;
                return;
            }
        } else {
            a -= d;
            if (a <= 0) {
                cout << "No" << endl;
                return;
            }
        }
        takahashi ^= 1;
    }
}

int main() {
    solve();
    return 0;
}
