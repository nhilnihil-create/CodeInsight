#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int N;

int main() {
    cin >> N;
    vector<ll> a(N);
    rep(i,N)  {
        cin >> a[i];
        if (a[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll res = 1LL;
    rep(i,N) {
        if (res <= 1000000000000000000 / a[i]) {
            res *= a[i];
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << res << endl;
}