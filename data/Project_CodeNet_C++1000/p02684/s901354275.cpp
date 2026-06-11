#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
    ll n, k;
    cin >> n >> k;
    int seen[n] = {0};
    vector<int> a(n), r;
    rep(i, n) cin >> a[i], a[i]--;
    int p = 0, time = 0;
    r.push_back(0);
    seen[0] = 1;
    while(1) { //次の場所に来ていない
        if(seen[a[p]]) {
            r.push_back(a[p]);
            break;
        }
        r.push_back(a[p]);
        seen[a[p]] = 1; //来たらチェック
        p = a[p];       //次の場所
    }

    //ループ開始を取得
    int start;
    rep(i, n) {
        if(r[i] == r[r.size() - 1]) {
            start = i;
            break;
        }
    }
    if(k <= start) { // ループが始まるより少ない
        cout << r[k] + 1 << endl;
    } else {
        cout << r[start + (k - start) % (r.size() - 1 - start)] + 1 << endl;
    }
    return 0;
}