// 6/30 解き直し
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 予めアルファベットごとに、sの中での登場indexをメモっておく。
// tを一文字ずつ見ていく。
// int cur_s = 0;
// for i in |t|:
//     sの中のindexを探す。（cur_sの次の）
//     なければ0から探す。
//     それでもなければ-1を返す。

int main() {
    string s, t;
    cin >> s >> t;

    int n = 26;
    vector<int> a[n];
    for (int i = 0; i < s.size(); i++) {
        a[s[i]-'a'].push_back(i);
    }

    // rep(i, 26) {
    //     printf("a")
    // }

    int cur_idx = 0;
    ll res = 0;
    for (int i = 0; i < t.size(); i++) {
        int p = t[i] - 'a';

        // そもそもsにpがない時はお手上げ。
        if (a[p].size()==0) {
            cout << "-1" << endl;
            return 0;
        }

        // cur_idx以降でいつ出てくるか。
        auto itr = lower_bound(a[p].begin(), a[p].end(), cur_idx);

        // if (next == a[p].size()) {
        if (itr == a[p].end()) {
            // もし出てこない場合は、次のところまで増やす。
            res += (s.size() - cur_idx);
            cur_idx = a[p][0] + 1;
            res += cur_idx;
        }
        else {
            // 出てきた場合はそこまで進める。
            res += (*itr - cur_idx + 1);
            cur_idx = *itr + 1;
        }

        // printf("p, next, res = %d, %d, %d\n", p, *itr, res);
    }

    cout << res << endl;
}