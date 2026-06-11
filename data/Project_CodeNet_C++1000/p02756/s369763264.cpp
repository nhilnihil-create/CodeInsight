#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    string s;
    int q;

    cin >> s;
    cin >> q;

    // dequeで文字列を持つ
    deque<string> dq;
    dq.push_front(s);

    // 反転していなければfalse 反転していたらtrue
    bool inversion = false;

    rep(i, q) {
        int t;
        cin >> t;

        if (t == 1) {
            // 文字列反転
            inversion = !inversion;
        } else if (t == 2) {
            int f;
            string c;

            cin >> f >> c;

            if (f == 1) {
                if (inversion == false) {
                    // 反転してないので先頭に追加
                    dq.push_front(c);
                } else if (inversion == true) {
                    // 反転しているので末尾に追加
                    dq.push_back(c);
                }
            } else if (f == 2) {
                if (inversion == false) {
                    // 反転してないので末尾に追加
                    dq.push_back(c);
                } else if (inversion == true) {
                    // 反転しているので先頭に追加
                    dq.push_front(c);
                }
            }
        }
    }

    string ans;

    for (auto itr = dq.begin(); itr != dq.end(); ++itr) {
        ans += *itr;
    }

    // 反転
    if (inversion == true) {
        reverse(ans.begin(), ans.end());
    }

    cout << ans << endl;
}
