#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n, max_num, ans;
    ans = 0;
    cin >> n;
    vector<ll> list(n);
    rep(i,n) cin >> list[i];
    rep(i,n) {
        if (i==0) {
            max_num = list[i];
            continue;
        } else {
            if (max_num > list[i]) {
                ans += (max_num - list[i]);
            } else {
                max_num = list[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}