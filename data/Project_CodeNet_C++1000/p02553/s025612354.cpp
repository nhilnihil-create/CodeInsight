#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;
 
int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll res = -INF;
    chmax(res, a * c);
    chmax(res, a * d);
    chmax(res, b * c);
    chmax(res, b * d);
    cout << res << endl;
    return 0;
}