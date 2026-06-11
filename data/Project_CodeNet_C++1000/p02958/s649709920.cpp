#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i, N) cin >> p.at(i);

    string ans = "NO";

    // 操作しない場合
    bool isAsc = true;
    rep(k, N - 1) {
        if (p.at(k + 1) <= p.at(k)) isAsc = false;
    }
    if (isAsc) ans = "YES";

    // 操作する場合
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(p.at(i), p.at(j));
            isAsc = true;
            rep(k, N - 1) {
                if (p.at(k + 1) <= p.at(k)) isAsc = false;
            }
            if (isAsc) ans = "YES";
            // rep(k, N) cout << p.at(k) << " ";
            // cout << endl;
            swap(p.at(i), p.at(j));  // 元に戻す
        }
    }

    cout << ans << endl;

    return 0;
}
