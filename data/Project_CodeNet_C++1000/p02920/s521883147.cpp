#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

typedef pair<int, int> P;

int main() {
    int N;
    cin >> N;
    int N2 = 1 << N;
    vector<int> a(N2);
    rep(i, N2) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> s; // 作成したスライムの集合
    s.push_back(a.back()); // 最初の世代に一番大きな数値を入れる
    a.back() = -1; // 使用済みフラグ

    rep(i, N) {
        vector<int> p = s; // p:親の世代
        sort(p.begin(), p.end());
        int ai = N2 - 1;
        while (p.size() > 0 && ai >= 0) {
            if (a[ai] == -1) {
                --ai;
                continue;
            }

            if (a[ai] < p.back()) {
                s.push_back(a[ai]); // p.back の子供としてa[ai]のスライムを作る
                p.pop_back();
                a[ai] = -1; // 使用済みフラグ
            }
            --ai;
        }

        if (p.size() > 0) { // 子供を作成出来ない親があった場合
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}