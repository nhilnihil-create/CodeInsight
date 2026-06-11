#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
template <class T> void corner(bool flg, T hoge) {
    if(flg) {
        cout << hoge << endl;
        exit(0);
    }
}
#define all(v) v.begin(), v.end()
#define inputv(v, n)                                                           \
    vl v;                                                                      \
    rep(i, n) {                                                                \
        ll x;                                                                  \
        cin >> x;                                                              \
        v.push_back(x);                                                        \
    }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N=500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
vl A,B(MAX_N,0);
map<ll,ll> dp;
int main() {
    cin >> n >> k;
    rep(i, n) {
        cin >> a;
        a--;
        A.push_back(a);
    }

    rep(i, n) {
        B[i+1] = B[i];
        B[i+1] += A[i];
    }

    ans = 0;
    auto ite1 = A.begin(), ite2 = A.begin();
    while (ite2 != A.end()) {
        dp[B[ite2 - A.begin()] % k]++;
        ite2++;
        while (ite2-ite1>=k) {
            dp[B[ite1 - A.begin()] % k]--;
            ite1++;
        }
        ans += dp[B[ite2 - A.begin()]%k];
    }
    cout << ans << endl;
}
