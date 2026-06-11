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


int G[100005];
int pos[100005];

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    memset(G, -1, sizeof(G));
    vector<VI> V(N + 1, VI(N - 1));
    FOR(i, 1, N) REP(j, N - 1) cin >> V[i][j];
    int days = 0;
    int total = (N * (N - 1)) / 2;
    while (total > 0) {
        days++;
        bool f = false;
        vector<bool> played(N+ 1, 0);
        FOR(i, 1, N) {
            if (pos[i] == N - 1) continue;
            if (played[i]) continue;
            int to = V[i][pos[i]];
            if (G[to] == i) {
                G[to] = -1;
                G[i] = - 1;
                f = true;
                total--;
                pos[i]++;
                pos[to]++;
                played[i] = true;
                played[to] = true;
            } else {
                G[i] = to;
            }
        }
        if (!f) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << days << "\n";
}