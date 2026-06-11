#include <bits/stdc++.h>

typedef long long ll;
const int INF = 1e9;

using namespace std; 

#define REP(inc, bgn, end) for (int inc = bgn; inc < end; inc++)

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n), a(n);
    REP(i, 0, n) cin >> p[i];
    REP(i, 0, n) cin >> q[i];

    /* 
    next_permutation()のための順列を作ります。
    この順列は、辞書順で一番小さいものです。
    */
    REP(i, 0, n) a[i] = i + 1;

    /* 
    連想配列に作った順列を格納ていきます。
    構造は以下のようになっています。
    Key: value = [順列]: 辞書順で数えたときの番号
    例) [1, 2, 3]: 1
     */
    map<vector<int>, int> mp;

    do {
        mp[a] = mp.size();
    } while (next_permutation(a.begin(), a.end()));

    int ans = abs(mp[p] - mp[q]);
    cout << ans << endl;
}