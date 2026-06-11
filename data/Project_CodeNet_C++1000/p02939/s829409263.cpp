#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

string S;
int main() {
    cin >> S;
    ll ans = 0;
    bool prev_one = false;

    rep(i, S.size()) {
        // 最後の2個
        if (i == S.size() - 2 && S[i] == S[i + 1]) {
            ans++;
            break;
        }

        // 直前の1個が同じ
        if (prev_one && S[i] == S[i - 1]) {
            // 2文字とる
            i++;
            ans++;
            prev_one = false;
        } else {
            // 1文字とる
            ans++;
            prev_one = true;
        }
    }
    cout << ans << endl;
}