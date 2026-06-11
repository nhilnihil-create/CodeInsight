#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define debug(...) cerr<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec)
{ for (auto v : vec) os << v << ' '; os << '\n'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{ os << '(' << pa.first << ',' << pa.second << ')'; return os; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{ cerr << " " << H; debug_out(T...); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

vector<ll> divs(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.emplace_back(i);
            if (i < n / i) ret.emplace_back(n / i);
        }
    }
    return ret;
}

int n, k;
vector<int> A;
bool check(int d) {
    int res = 0, res2 = 0;
    vector<int> rem(n);
    rep(i, n) rem[i] = A[i] % d;
    sort(all(rem));
    int r = n - 1;
    rep(l, n) {
        res += rem[l];
        while(res > res2) res2 += d - rem[r], r--;
//        debug(res, res2);
        if (r <= l) break;
    }
    return res <= k;
}

void solve() {
    cin >> n >> k;
    int sum = 0;
    A.resize(n);
    for(auto &a : A) cin >> a, sum += a;
    auto div = divs(sum);
    sort(all(div), greater<>());
    for (int d : div) {
        if (check(d)) {
            cout << d << endl;
            return;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
