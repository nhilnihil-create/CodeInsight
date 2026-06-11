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
    ll N,K;
    cin >> N >> K;
    vl A(N);
    rep(i, N){
        cin >> A[i];
    }
    vl ac(N+1, 0);
    // 累積和の各要素で１ずつ引くとindex分だけ引ける
    rep(i, N) ac[i + 1] = (ac[i] + A[i] - 1) % K;

    map<ll,ll> m;
    ll ans = 0;
    rep(i,N+1){
        if (i >= K) m[ac[i - K]]--;
        ans += m[ac[i]]++;
    }

    cout << ans << endl;
    
    

    



    

}