//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vi v(3);
    ll ans=1LL;
    rep(i, n) {
        ll c=0LL;
        int j_;
        rep(j, 3) {
            if(v[j]==a[i]) {
                ++c;
                j_ = j;
            }
        }
        v[j_]++;
        ans *= c;
        ans %= mod;
    }
    cout << ans << '\n';
}