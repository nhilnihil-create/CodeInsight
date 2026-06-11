#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


string s;
bool can_reach(int l, int r) {
    for (int i = l; i < r; i++) {
        if (s[i] == s[i+1] && s[i] == '#') {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d >> s;
    a--;
    b--;
    c--;
    d--;

    // 1. a b c d: b -> d 間に岩が2個並んでいるところがない かつ、 a -> c ...
    // 2. a c b d: ..
    // 3. a b d c: a が b を追い越すことができる. 3連続の空きがあり、かつ、右端がb じゃない

    if (!can_reach(a,c) || !can_reach(b,d)) {
        cout << "No" << endl;
        return;
    }

    if (c > d) {
        int ok = 0;
        for (int i = b; i <= d; i++) {
            if (s[i-1] == s[i] && s[i] == s[i+1] && s[i] == '.') {
                ok = 1;
            }
            if (ok) break;
        }
        if (!ok) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;

}

int main() {
    solve();
    return 0;
}


