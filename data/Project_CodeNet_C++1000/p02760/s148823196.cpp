#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    vector<vector<int>> A(3, vector<int>(3));
    rep(i, 3) {
        rep(j, 3) {
            cin >> A.at(i).at(j);
        }
    }
    int N;
    cin >> N;
    vector<int> b(N);
    rep(i, N) cin >> b.at(i);

    rep(i, N) {
        rep(j, 3) {
            rep(k, 3) {
                if (b.at(i) == A.at(j).at(k))
                    A.at(j).at(k) = 0;
            }
        }
    }

    string ans = "No";
    rep(i, 3) {  // 横
        if (A.at(i).at(0) == 0 && A.at(i).at(1) == 0 && A.at(i).at(2) == 0) ans = "Yes";
    }
    rep(i, 3) {  // 縦
        if (A.at(0).at(i) == 0 && A.at(1).at(i) == 0 && A.at(2).at(i) == 0) ans = "Yes";
    }

    // 左下向き斜め
    if (A.at(0).at(0) == 0 && A.at(1).at(1) == 0 && A.at(2).at(2) == 0) ans = "Yes";

    // 右上向き斜め
    if (A.at(2).at(0) == 0 && A.at(1).at(1) == 0 && A.at(0).at(2) == 0) ans = "Yes";

    cout << ans << endl;

    return 0;
}
