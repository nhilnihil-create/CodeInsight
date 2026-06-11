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

void solve() {
    string s, t;
    cin >> s >> t;
    set<int> index[26];
    rep(i, (int)s.size()) {
        index[s[i] - 'a'].emplace(i);
    }
    rep(i, (int)t.size()) {
        if (index[t[i] - 'a'].empty()) {
            cout << -1 << endl;
            return;
        }
    }
    ll ans = 0;
    int cur = 0;
    rep(i, (int)t.size()) {
        int j = t[i] - 'a';
        set<int>::iterator itr = index[j].lower_bound(cur);
        if (itr == index[j].end()) {
            itr = index[j].begin();
            ans += s.size();
        }
        cur = *itr + 1;
    }
    ans += cur;
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
