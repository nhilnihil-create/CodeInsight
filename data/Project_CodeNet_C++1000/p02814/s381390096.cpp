//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;

int64_t gcd(int64_t a, int64_t b) {return b?gcd(b, a%b):a;}
int64_t lcm(int64_t a, int64_t b) {return a/gcd(a,b)*b;}

int main() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
        a[i] /= 2LL;
    }
    int b = __builtin_ctzll(a[0]);
    rep(i, n-1) {
        if(b != __builtin_ctz(a[i+1])) {
            cout << 0 << endl;
            return 0;
        }
    }


    ll x = 1LL;
    rep(i, n) {
        x = lcm(a[i], x);
        if(x > (ll)1e11+10LL) {
            cout << 0 << endl;
            return 0;
        }
    }

    int ans = m/x;
    ans = (ans + 1)/2;

    cout << ans << endl;
}