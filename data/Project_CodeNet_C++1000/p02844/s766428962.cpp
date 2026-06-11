#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    rep(i, 1000) {
        int c[3] = {i / 100, (i / 10) % 10, i % 10};
        int f = 0;
        rep(j, n) {
            if (s[j] == ('0' + c[f])) {
                f++;
            }
            if (f == 3) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;

}

int main() {
    solve();
    return 0;
}
