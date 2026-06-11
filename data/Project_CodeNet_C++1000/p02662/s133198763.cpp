#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll MOD = 998244353;
const ll inf = 1e18;

template<typename T>
// return a ^ b % MOD
T mypow(T a, T b){
    if (b == 0)
        return 1;
    T tmp = mypow(a, b / 2);
    if (b % 2)
        return (((tmp * tmp) % MOD) * a) % MOD;
    else
        return (tmp * tmp) % MOD;
}

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll n, s;
    cin >> n >> s;
    vll a(n);
    REP(i, n) cin >> a[i];

    // dp[i + 1][j] : i 番目まで見て和が j となる添え字集合を含む集合の個数
    vvll dp(3010, vll(3010));
    dp[0][0] = 1;
    REP(i, n) {
        REP(j, s + 1) {
            dp[i + 1][j] += 2 * dp[i][j];
            dp[i + 1][j] %= MOD;
            if (j + a[i] <= s) {
                dp[i + 1][j + a[i]] += dp[i][j];
                dp[i + 1][j + a[i]] %= MOD;
            }
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}