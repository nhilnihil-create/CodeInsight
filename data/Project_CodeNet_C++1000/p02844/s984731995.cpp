#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int ans = 0;
    rep(i, 10) rep(j, 10) rep(k, 10) {
        int cnt = 0;
        rep(l, N) {
            if (cnt == 0 && S[l] == '0' + i) {
                ++cnt;
                continue;
            }
            if (cnt == 1 && S[l] == '0' + j) {
                ++cnt;
                continue;
            }
            if (cnt == 2 && S[l] == '0' + k) {
                ++cnt;
                continue;
            }
        }
        if (cnt == 3) ++ans;
    }
    cout << ans << endl;
}