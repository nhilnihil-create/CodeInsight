#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }

    // 全体 - k番目との組の数 で求める値が得られる

    // 値:個数 のmap
    map<long long, long long> mp;
    rep(i, n) {
        long long value = a.at(i);
        mp[value] += 1;
    }

    // 値:値ごとの組み合わせの数
    map<long long, long long> cmb_mp;
    for (auto itr : mp) {
        cmb_mp[itr.first] = itr.second * (itr.second - 1) / 2;
    }

    // 全体は全て足す
    long long whole = 0;
    for (auto itr : cmb_mp) {
        whole += itr.second;
    }

    // 答え
    rep(i, n) {
        long long value = a.at(i);
        long long part = mp.at(value) - 1;

        cout << whole - part << endl;
    }
}
