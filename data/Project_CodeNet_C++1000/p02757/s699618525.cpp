#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
// この方法で関数を出せば多分できる
// https://nlab.itmedia.co.jp/nl/articles/1805/04/news002.html

const int MAX = 100 / 0.08;
int main() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if (10%p == 0) { // pが2 or 5
        ll ans = 0;
        // 2か5で割り切れるというのは、1桁目を見るだけで判断可能なので
        // 1桁目の余りが0だったらOK
        // 通り数は、桁数と同等なのでr+1をnまで足せばOK
        rep(r, n) {
            if ((s[r]-'0') % p == 0) {
                ans += r+1;
            }
        }
        cout << ans << endl;
        return 0;
    }

    // 累積和の配列
    // 各桁の余りの合計
    vector<int> d(n+1);
    int ten = 1;
    // 1桁目から計算する
    for (int i = n - 1; i >= 0; --i) {
        int a = (s[i]-'0') * ten % p;
        d[i] = (d[i+1]+a) % p;
        ten *= 10; ten %= p;
    }
    vector<int> cnt(p);
    ll ans = 0;
    for (int i = n; i >= 0; --i) {
        ans += cnt[d[i]];
        cnt[d[i]]++;
    }
    cout << ans << endl;
    return 0;
}
