#include <bits/stdc++.h>
using namespace std;

string to_string(const string& s) { return '"' + s + '"'; }
string to_string(char c) { string s = "'"; s += c; return s + "'"; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) res += ", ";
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <typename A>
string to_string(A v) {
    bool first = true; 
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}"; 
    return res;
}
istream_iterator<string> eos;
void dbg_out(istream_iterator<string> it) { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(istream_iterator<string> it, Head H, Tail... T) {
    cerr << *it << " = " << to_string(H);
    if(++it != eos) cerr << ", ";
    dbg_out(it, T...);
}
#ifdef LOCAL
    #define dbg(...) { string _s = #__VA_ARGS__; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); dbg_out(_it, __VA_ARGS__); }
#else
    #define dbg(...)
#endif

#define int long long
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define sz(v) ((int)(v).size())
#define fr(i, j, k) for(int i = j; i < k; i++)
#define nl "\n"
typedef pair<int, int> pii;
typedef vector <int> vi;

pii dir[8] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1} , {-1, 1}, {1, -1} };

const int inf = (1LL << 60), mod = 998244353, nn = 3003;

void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n+1, vector<int>(s+1));
    
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= s; j++) {
            dp[i][j] = 2 * dp[i-1][j] % mod;
            if(j >= a[i]) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-a[i]]) % mod;
            }
        }
    }
    cout << dp[n][s] << '\n';
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}