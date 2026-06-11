#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(char c) { string s = "'"; s += c; return s + "'"; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } 
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
#define MP make_pair
#define sz(v) ((int)(v).size())
#define fr(i, j, k) for(int i = j; i < k; i++)
#define nl "\n"
typedef pair<int, int> pii;
typedef vector <int> vi;

pii dir[8] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1} , {-1, 1}, {1, -1} };

const int inf = (1LL << 60), mod = 1e9+7, nn = 2e5+5;

void solve(){
    int n;
    cin >> n;
    vector<int> leaves(n+1), suf_leaves(n+2);
    for(int i = 0; i <= n; i++) cin >> leaves[i];

    for(int i = n; i >= 0; i--) {
        suf_leaves[i] = suf_leaves[i+1] + leaves[i];
    }
    int ans = 0, nodes = 1;

    for(int d = 0; d <= n; d++) {
        if(nodes < leaves[d]) {
            cout << -1 << '\n';
            return;
        }
        ans += nodes;

        // for next level
        nodes -= leaves[d];
        nodes *= 2;
        nodes = min(nodes, suf_leaves[d+1]);    // at some level, all subtree leaf nodes will have a single chain in order to maximise nodes
    }
    cout << ans << '\n';
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