#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
#define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep (i, n) cin >> a[i];
    string s;
    cin >> s;

    vector<ll> basis;
    ll mask = (1LL << 62) - 1;
    rrep (i, s.size()) {
        if (s[i] == '0') {
            ll now = a[i];
            for (ll b: basis) {
                chmin(now, now ^ b);
            }
            if (now > 0) {
                basis.push_back(now);
                mask = mask & (~now);
            }
        }
        else {
            ll x = a[i];
            for (ll b: basis) {
                ll temp = 1LL << 62;
                while ((temp & b) == 0) temp >>= 1;
                if (x & temp) x ^= b;
            }
            if (x != 0) {
                cout << 1 << endl;
                return;
            }
        }
    }
    // DEBUG_VEC(basis);
    cout << 0 << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}

// ll solve1(int n, int a, int b) {
//     vector<vll> dp(n + 1, vll(b + 1, vl(2)));
//     dp[0][0][0] = 1;
//     rep (i, n) {
//         rep (j, b + 1) {
//             rep (k, 2) {
//                 if (dp[i][j][k] == 0) continue;
//                 (dp[i + 1][0][k] += dp[i][j][k]) %= MOD;
//                 int nk = k, nj = j + 1;
//                 if (nj > b) nj = b;
//                 if (nj == b) nk = 1;
//                 (dp[i + 1][nj][nk] += dp[i][j][k]) %= MOD;
//             }
//         }
//     }

//     ll ans = 0;
//     rep (j, b + 1) ans += dp[n][j][1];
//     ans %= MOD;
//     return ans;
// }

// ll solve2(int n, int a, int b) {
//     vll dp(n + 1, vl(b));
//     dp[0][0] = 1;
//     rep (i, n) {
//         rep (j, b) {
//             if (dp[i][j] == 0) continue;
//             if (j != b - 1) {
//                 (dp[i + 1][j + 1] += dp[i][j]) %= MOD;
//             }
//             for (int ni = i + 2; ni <= n; ni++) {
//                 if (ni - i - 1 < a) {
//                     if (n - ni + 1 >= b) (dp[ni][0] += dp[i][j]) %= MOD;
//                 }
//                 else {
//                     (dp[ni][0] += dp[i][j]) %= MOD;
//                 }
//             }
//         }
//     }
//     ll ans = 0;
//     rep (i, b) ans += dp[n][i];
//     ans %= MOD;
//     return ans;
// }

// signed main() {
//     int n, a, b;
//     cin >> n >> a >> b;
//     if (a > b) swap(a, b);

//     ll ans = solve1(n, a, b);
//     ans += solve2(n, a, b);
//     ans %= MOD;
//     cout << ans << endl;
// }

// bool check(string s, int m) {
//     DEBUG(m);
//     pii left(0, 0), right(0, 0), st(0, 0), en(0, 0);
//     bool is_left = true, is_right = true;
//     bool is_range = false;
//     rep (i, s.size()) {
//         if (s[i] == '0') {
//             if (not is_range) {
//                 if (is_right and right.second > 0) {
//                     is_range = true;
//                     st = right;
//                     en = right;
//                 }
//             }
//             if (is_range) {
//                 if (is_right and (en.second - en.first == right.second - right.first)) en = right;
//                 st.first--; 
//                 st.second--;
//                 en.first--;
//                 en.second--;
//             }
            
//             if (is_left) {
//                 left.first--;
//             }
//             is_right = false;

//         }
//         else if (s[i] == '1') {
//             if (not is_range) {
//                 if (is_left and left.first < 0) {
//                     is_range = true;
//                     st = left;
//                     en = left;
//                 }
//             }
//             if (is_range) {
//                 if (is_left and (st.second - st.first == left.second - left.first)) st = left;
//                 st.first++;
//                 st.second++;
//                 en.first++;
//                 en.second++;
//             }
//             is_left = false;
//             if (is_right) {
//                 right.second++;
//             }
//         }
//         else {
//             if (is_range) {
//                 st.first--;
//                 st.second--;
//                 en.first++;
//                 en.second++;
//                 if (is_left and (st.second - st.first == left.second - left.first)) {
//                     pii new_st = left;
//                     new_st.first++;
//                     new_st.second++;
//                     if (new_st < st) st = new_st;
//                 }
//                 if (is_right and (en.second - en.first == right.second - right.first)) {
//                     pii new_en = right;
//                     new_en.first--;
//                     new_en.second--;
//                     if (en < new_en) en = new_en;
//                 }
//             }
//             else {
//                 if ((is_left and left.first < 0) and (is_right and right.second > 0)) {
//                     is_range = true;
//                     st = left;
//                     st.first++;
//                     st.second++;
//                     en = right;
//                     en.first--;
//                     en.second--;
//                     if (st.first <= en.first and en.second <= st.second) st = en;
//                     if (en.first <= st.first and st.second <= en.second) en = st;
//                     if (en < st) swap(st, en);
//                 }
//                 else if (is_left and left.first < 0) {
//                     is_range = true;
//                     st = left;
//                     en = left;
//                     st.first++;
//                     st.second++;
//                     en.first++;
//                     en.second++;
//                 }
//                 else if (is_right and right.second > 0) {
//                     is_range = true;
//                     st = right;
//                     en = right;
//                     st.first--;
//                     st.second--;
//                     en.first--;
//                     en.second--;
//                 }
//             }
//             if (is_left) {
//                 left.first--;
//             }
//             if (is_right) {
//                 right.second++;
//             }
//         }
//         if (is_range and st.second == 0) {
//             if (not is_left or left.first < st.first) {
//                 is_left = true;
//                 left = st;
//             }
//             st.first += 2;
//             st.second += 2;
//         }
//         if (is_range and en.first == 0) {
//             if (not is_right or en.second < right.second) {
//                 is_right = true;
//                 right = en;
//             }
//             en.first -= 2;
//             en.second -= 2;
//         }
//         if (is_left) {
//             if (left.first < -m) is_left = false;
//         }
//         if (is_right) {
//             if (right.second > m) is_right = false;
//         }
//         while (st.first < -m) {
//             st.first += 2;
//             st.second += 2;
//         }
//         while (en.second > m) {
//             en.second -= 2;
//             en.second -= 2;
//         }

//         if (st > en or st.second > m or en.first < -m) is_range = false;
//         if (not is_left and not is_right and not is_range) {
//             return false;
//         }
//         if (m == 4) {
//             for (int j = 0; j <= i; j++) {
//                 cout << s[j];
//             }
//             cout << endl;
//             DEBUG(is_left);
//             DEBUG(left);
//             DEBUG(is_right);
//             DEBUG(right);
//             DEBUG(is_range);
//             DEBUG(st);
//             DEBUG(en);
//             cout << endl;
//         }
//     }
//     return true;

// }

// signed main() {
//     fio();
//     string s;
//     cin >> s;
//     int n = s.size();
//     int ng = 0, ok = n;

//     while (ng + 1 < ok) {
//         int mid = (ok + ng) / 2;
//         if (check(s, mid)) {
//             ok = mid;
//         }
//         else {
//             ng = mid;
//         }
//     }
//     cout << ok << endl;
// }