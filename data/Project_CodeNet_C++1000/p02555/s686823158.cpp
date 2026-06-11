#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> dp(n + 1);
    dp.at(0) = 1;
    ll sm = 0;
    mrep(i, 1, n + 1){
        if(i >= 3){
            sm = (sm + dp.at(i - 3)) % mod;
        }
        dp.at(i) = sm % mod;
    }
    cout << dp.at(n) << endl;
    return 0;
}