//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vi a(n), f(n);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> f[i];
    }

    sort(all(a));
    sort(rall(f));
    vi mul(n);
    rep(i, n) {
        mul[i] = a[i] * f[i];
    }
    
    auto check = [&](ll X) {
        ll cou = 0;
        rep(i, n) {
            if(mul[i] > X) {
                cou += (mul[i]-X + f[i] - 1)/f[i];
            }
        }
        return cou;
    };

    ll al = -1, ga = LINF;
    ll be;
    while(ga-al != 1) {
        be = (al + ga)/2;
        if(check(be) <= k) {
            ga = be;
        } else {
            al = be;
        }
    }

    cout << ga << endl;
}