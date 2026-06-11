#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }
#define INF 1e10

int main() {
    ll n, d;
    cin >> n >> d;
    vector<ll> x(n);
    vector<ll> y(n);
    int ans = 0;
    rep(i, n){
        cin >> x.at(i) >> y.at(i);
        if(x.at(i) * x.at(i) + y.at(i) * y.at(i) <= d * d){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}