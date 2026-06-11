#include <bits/stdc++.h>
using namespace std;

// #define int long long // intで書いたけど心配なときにlong longに変換する
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

/* short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)
#define X real()
#define Y imag()

/* REPmacro */
#define REPS(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (ll i = (a); i >= (ll)(n); --i)
#define DEP(i, n) DEPS(i, n, 0)
#define EACH(i, n) for (auto&& i : n)

/* debug */
#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

/* alias */
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using plglg = pair<ll, ll>;
using tlglglg = tuple<ll, ll, ll>;
using D = double;
using P = complex<D>;
using vs = vector<string>;
template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

/* const */
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;
const D EPS = 1e-9;
const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

/* func */
inline bool inside(int y, int x, int H, int W) {return y >= 0 && x >= 0 && y < H && x < W;}
inline int in() {int x; cin >> x; return x;}
inline ll IN() {ll x; cin >> x; return x;}
inline vs split(const string& t, char c) {vs v; stringstream s(t); string b; while(getline(s, b, c)) v.eb(b); return v;}
template <typename T> inline bool chmin(T& a, const T& b) {if (a > b) a = b; return a > b;}
template <typename T> inline bool chmax(T& a, const T& b) {if (a < b) a = b; return a < b;}
template <typename T, typename S> inline void print(const pair<T, S>& p) {cout << p.first << " " << p.second << endl;}
template <typename T> inline void print(const T& x) {cout << x << endl;}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v) {for (auto&& p : v) print(p);}
template <typename T> inline void print(const vector<T>& v, string s = " ") {REP(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}
inline void yesno(bool ok, string yes = "Yes", string no = "No") {cout << (ok?yes:no) << endl;}


signed main() {
    //my-code
    string s; cin >> s;
    string t; cin >> t;
    map<char, int> smp;
    map<char, int> tmp;
    REP(i, s.length()) {
        smp[s[i]]++;
    }
    REP(i, t.length()) {
        tmp[t[i]]++;
    }

    bool ok = true;
    for (char c = 'a'; c <= 'z'; c++) {
        if (tmp[c]!=0 && smp[c]==0) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        print(-1);
        return 0;
    }

    string ss = s + s;
    vvll nappear(26, vll(2*s.length(), 0));
    char c;
    DEPS(i, 2*s.length()-1, 1) {
        for (int ci=0; ci<26; ci++) {
            c = 'a' + (char)ci;
            if (ss[i] == c) {
                nappear[ci][i-1] = 1;
            } else {
                nappear[ci][i-1] = nappear[ci][i] + 1;
            }
        }
    }

    // for (int ci=0; ci<26; ci++) {
    //     cout << (char)('a'+(char)ci) << ':';
    //     print(nappear[ci]);
    // }

    char target_c;
    int tci;
    ll rel_pos = 0;
    ll ans = 1;
    REP(i, t.length()) {
        target_c = t[i];
        if (i==0) {
            if (s[rel_pos] == target_c) continue;
        }
        tci = (int)(target_c - 'a');
        ans += nappear[tci][rel_pos];
        rel_pos = (rel_pos+nappear[tci][rel_pos]) % s.length();
    }

    print(ans);

    return 0;
}

// https://github.com/kurokoji/.cpp-Template/wiki テンプレートについて
// http://www.creativ.xyz/dump-cpp-652 dump()について
// https://gist.github.com/rigibun/7905920 色々