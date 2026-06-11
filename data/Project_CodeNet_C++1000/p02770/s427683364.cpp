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
ll gcd(ll a,ll b){
    if (a < b) swap(a, b);
    ll r = a % b;
    while(r){
        a = b, b = r;
        r = a % b;
    }
    return b;
}
int main() {
    init();
    ll K, Q;
    cin >> K >> Q;
    vl D(K);
    rep(i, K) cin >> D[i];

    while(Q--){
        ll N, X, M;
        cin >> N >> X >> M;
        ll ans = 0;
        N--;

        vl Dm(K);
        rep(i, K) Dm[i] = (D[i] % M == 0 ? M : D[i] % M);
        ll sumDm = 0;
        rep(i, K) sumDm += Dm[i];

        ll sum = X % M, loop = N / K, rem = N % K;
        sum += sumDm * loop;
        rep(i,K){
            if (i < rem) sum += Dm[i];
        }
        ans = N - sum / M;

        cout << ans << endl;
    }
}