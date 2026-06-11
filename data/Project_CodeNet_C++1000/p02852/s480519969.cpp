// 6/23 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

vector<int> f;  // iマス目以降で一番小さい0のマス。

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;

    f.resize(N + 1);
    int last = N + 1;  // Nマス目は必ずゴール。
    for (int i = N; i >= 0; i--) {
        if (S[i] == '0') {
            f[i] = i;
            last = i;
        } else {
            // ゲームオーバーのマス
            f[i] = last;
        }
    }

    // for (auto x : f) {
    //     cout << x;  //  << endl;
    // }
    // cout << endl;

    vector<int> res;

    int pos = N;
    while (pos > 0) {
        // cout << "pos: " << pos << endl;
        int next_pos = pos - M;
        if (next_pos <= 0) {
            // ゴールにつける。
            res.push_back(pos);
            pos = next_pos;
        }
        else if (f[next_pos] == next_pos) {
            // M手先は行けるので、そのまま進む。
            res.push_back(M);
            pos -= M;
        } else if (f[next_pos] < pos) {
            // M手先はゲームオーバーマスだが、1以上の手で進めることは進める。
            // cout << "here?" << endl;
            res.push_back(pos - f[next_pos]);
            pos = f[next_pos];
        } else {
            // それ以外の時はもう進めない。
            cout << -1 << endl;
            return 0;
        }
    }

    reverse(res.begin(), res.end());
    // for (auto r : res) {
    //     cout << r << 
    // }
    for (int i = 0; i < res.size(); i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
}