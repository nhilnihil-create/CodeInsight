#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;
 
int main() {
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    ll d2 = d*d;
    ll count = 0;
    rep(i,n) {
        if (x[i] * x[i] + y[i] * y[i] <= d2 ) count++;
    }
    cout << count << endl;
    return 0;
}