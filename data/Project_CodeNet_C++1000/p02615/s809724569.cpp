/*模範解答*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll ans = 0;
    int t = n - 1;
    rep(i, n){
        int lim = 2;
        if(i == 0) lim = 1;
        rep(j, lim){
            if(t > 0){
                ans += a.at(i);
                t--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}