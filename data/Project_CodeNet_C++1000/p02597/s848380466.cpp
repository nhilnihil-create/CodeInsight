#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

const ll mod = 1000000007;

int main() {
    int N;
    cin >> N;
    string c;
    cin >> c;

    int r_to_w = 0;
    int w_to_r = 0;

    rep(i, N) if (c[i] == 'R') r_to_w++;
    int ans = r_to_w;

    rep(i, N) {
        if (c[i] == 'R') {
            r_to_w--;
        } else {
            w_to_r++;
        }
        chmin(ans, chmax(r_to_w, w_to_r));
    }

    cout << ans << endl;
}
