#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<st> s(h);
    rep(i, h) cin >> s.at(i);
    int ans = 0;
    rep(is, 1 << h){
        rep(js, 1 << w){
            int cnt = 0;
            rep(i, h){
                rep(j, w){
                    if(is >> i & 1) continue;
                    if(js >> j & 1) continue;
                    if(s.at(i).at(j) == '#') cnt++;
                }
            }
            if(cnt == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}