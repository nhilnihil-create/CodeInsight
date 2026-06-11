#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n;
string s;

bool check(int a, int b, int c) {
    int idx = 0;
    bool truth = false;
    rep(i, n) {
        if (s[i] == (a + '0')) {
            idx = i;
            truth = true;
            break;
        }
    }
    if (!truth) return false;
    truth = false;
    for (int i = idx+1; i < n; i++) {
        if (s[i] == (b + '0')) {
            idx = i;
            truth = true;
            break;
        }
    }
    if (!truth) return false;
    truth = false;
    for (int i = idx+1; i < n; i++) {
        if (s[i] == (c + '0')) {
            truth = true;
            break;
        }
    }

    return truth;
}

void solve() {
    cin >> n >> s;

    int ans = 0;
    rep(i, 10) rep(j, 10) rep(k, 10) if (check(i, j, k)) ans++;
    cout << ans << endl;

}

int main() {
    solve();
    return 0;
}
