#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()    // 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend() // 降順ソート 例：sort(DESC(vec));
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i < n; i++)
#define REP(i, vec) for (auto i = vec.begin(); i != vec.end(); ++i)

const int       mod = 1000000007;
const int       inf = (1 << 21);
const long long INF = 1LL << 60;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vii = vector<pair<int, int>>;
using vll = vector<pair<ll, ll>>;

template<class T>
inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T>
inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T>
T GCD(T a, T b) { if (b == 0) return a; else return GCD(b, a % b); }
template<class T>
T LCM(T a, T b) { return a / GCD(a, b) * b; }

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

#define each(i, mp) for(auto& i:mp)

int main() {
    string s;
    cin >> s;
    map<ll, ll> mp;
    mp[0] = 1;
    reverse(s.begin(), s.end());
    ll now = 0, ten = 1;
    each(e, s) {
        //cout << now << endl;
        now = (now + (e - '0') * ten) % 2019;
        ten *= 10;
        ten %= 2019;
        mp[now]++;
    }
    ll ans = 0;
    each(e, mp) {
        ans += e.second * (e.second - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}