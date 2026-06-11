#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)
#define repa(i,n) for (auto& i: n)

template<class T> inline bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1;} return 0;}
struct init{init(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}init_;

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cerr << a[i] << " "; cerr << "\n" << flush; }
ll dbgt = 1; void err() { cerr << "passed " << dbgt++ << "\n" << flush; }
template<class H, class... T> void err(H&& h,T&&... t){ cerr<< h << (sizeof...(t)?" ":"\n") << flush; if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

const ll INF = 4e18;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
//--------------------------------------------------------------------------------//
ll dp[200005][2];

int main() {
    string S;
    cin >> S;
    ll N = S.size();

    dp[1][0] = 1;
    repe(i, 1, N){
        if (S[i - 1] != S[i]) chmax(dp[i + 1][0], dp[i][0] + 1);
        chmax(dp[i + 1][0], dp[i][1] + 1);
        chmax(dp[i + 1][1], dp[i - 1][0] + 1);
    }

    cout << max(dp[N][0], dp[N][1]) << endl;
}