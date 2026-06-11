#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll M;
vector<ll> d, c;
int main() {
    cin >> M;
    d.resize(M);
    c.resize(M);

    rep(i, M) {
        cin >> d[i] >> c[i];
    }
    ll ans = accumulate(c.begin(), c.end(), 0LL) - 1;

    ll tmp = 0;
    rep(i, M) {
        tmp += d[i] * c[i];
    }

    // if (tmp >= 10) {
        ans += (tmp - 1) / 9;
    // }

    cout << ans << endl;
}