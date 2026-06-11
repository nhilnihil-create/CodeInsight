#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
const ll INF = 1e14;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N;
    cin >> N;
    vl A(N);
    rep(i, N){
        ll a;
        cin >> a;
        A[a - 1] = i + 1;
    }

    set<ll> S = {0, 0, N + 1, N + 1, A[N-1]};
    ll ans = 0;
    repr(x,N-1){
        S.emplace(A[x]);
        auto it = S.find(A[x]);
        auto l = prev(it, 1), r = next(it, 1);
        if (*l != 0){
            auto l2 = prev(l, 1);
            ans += (x + 1) * (*r - *it)*(*l - *l2); //(l,it)をitが２番目となる最小の範囲として、２番目が変わらない左右の範囲を考える
        }
        if (*r != N + 1){
            auto r2 = next(r, 1);
            ans += (x + 1) * (*it - *l)*(*r2 - *r);  //(it,r)も同様
        }
    }
    cout << ans << endl;
}