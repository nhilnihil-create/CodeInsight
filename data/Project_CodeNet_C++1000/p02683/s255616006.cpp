#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    // n*mの配列
    vector<vector<long long> > a(n, vector<long long>(m));
    rep(i, n) {
        cin >> c.at(i);
        rep(j, m) {
            cin >> a.at(i).at(j);
        }
    }

    // 全ての参考書の組み合わせをbit全探索で調べる(n冊ある内のi番目)

    vector<long long> satisfied_money;

    for (int bit = 0; bit < (1 << n); ++bit) {
        // 行の組み合わせをもつ配列
        vector<int> row;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {  // 列挙に(nの内)i行目が含まれるか
                row.push_back(i);
            }
        }

        // 満たすかの確認

        // 金額
        long long money = 0;

        // 理解度
        vector<long long> understanding(m);

        // 行を全て回す
        for (int i = 0; i < (int)row.size(); ++i) {
            // 行番号num
            int num = row.at(i);
            money += c.at(num);

            // 列を全て回す
            rep(j, m) {
                understanding.at(j) += a.at(num).at(j);
            }
        }

        bool ok = true;

        rep(i, m) {
            if (understanding.at(i) < x) {
                ok = false;
                break;
            }
        }

        // 条件を満たすなら追加
        if (ok) {
            satisfied_money.push_back(money);
        }
    }

    // satisfied_moneyの内の最小値を出力
    long long size = satisfied_money.size();
    if (size == 0) {
        cout << -1 << endl;
    } else if (size > 0) {
        long long mininum = *min_element(satisfied_money.begin(), satisfied_money.end());
        cout << mininum << endl;
    }
}
