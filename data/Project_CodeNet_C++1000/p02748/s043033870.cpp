#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t anum,bnum,m;
    cin >> anum >> bnum >> m;
    vi a(anum),b(bnum);
    rep(i,anum) cin >> a.at(i);
    rep(i,bnum) cin >> b.at(i);
    vi x(m),y(m),c(m);
    rep(i,m) cin >> x.at(i) >> y.at(i) >> c.at(i);
    int64_t res = INF;
    // 割引券を使う場合
    int64_t sum = 0;
    rep(i,m){
        sum = a.at(x.at(i)-1) + b.at(y.at(i)-1) - c.at(i);
        res = min(res,sum);
    }
    // 割引券を使わない場合
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sum = a.at(0) + b.at(0);
    res = min(res,sum);
    cout << res << endl;
}