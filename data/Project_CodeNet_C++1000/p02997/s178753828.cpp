#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
using ull = uint64_t;
using ll = int64_t;
using PII = pair<int, int>;
using VI = vector<int>;

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(A v) {
bool first = true; string res = "{";
for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); }
res += "}"; return res; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H); debug_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<PII> ans;
    if (K > ((N - 1) * (N - 2)) / 2) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 2; i <= N; i++) {
        ans.pb({1, i});
    }
    int cur = ((N - 1) * (N - 2)) / 2; 
    for (int i = 2; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (cur <= K) {
                break;
            }
            ans.pb({i, j});
            cur--;
        }
    }

    cout << SZ(ans) << "\n";
    REP(i, SZ(ans)) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

}