#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
#define ITR(v, i) for(auto ite = v.begin(); ite != v.end(); ite++)
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vl A, B;
    rep(i, n) {
        cin >> x;
        A.push_back(x);
        B.push_back(x);
    }

    rep(i, n) { a = a ^ A[i]; }

    vl used(n, 0);
    p = 0;

    rep(i, 61) {
        if(a & (1LL << (60 - i)))
            continue;
        rep(j, n) {
            if((A[j] & (1LL << (60 - i)) && !used[j])) {
                used[j] = 1;
                rep(k, n) {
                    if((A[k] & (1LL << (60 - i))) && j != k) {
                        A[k] = A[j] ^ A[k];
                    }
                }
                goto next;
            }
        }
    next:
        // cout << i << " " << ans << endl;
        q = 1;
        // cout << A[0] << " " << A[1] << " " << A[2] << " " << A[3] << endl;
    }

    /*sort(all(A));
    reverse(all(A));*/

    rep(i, n) p ^= A[i];
    // cout << a << " " << p << endl;

    cout << p + (a ^ p) << endl;
}