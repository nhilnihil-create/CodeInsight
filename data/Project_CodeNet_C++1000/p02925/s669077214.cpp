#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

vector<vector<int>> G;
vector<int> d;
vector<bool> seen;
vector<bool> finished;
bool cycle;

void dfs(int v) {
    if (finished[v]) return;
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv] && !finished[nv]) {
            cycle = true;
            return;
        }
        dfs(nv);
        if (cycle) return;

        chmax(d[v], d[nv] + 1);
    }

    finished[v] = true;
}


int main(){
    int n;
    cin >> n;
    int size = n * (n-1) / 2 + 1;
    G.resize(size);
    int a;
    for (int i = 0; i < n; ++i) {
        int now = 0;
        int next;
        for (int j = 0; j < n-1; ++j) {
            cin >> a;
            a--;
            if (i < a) next = a * (a-1) / 2 + i + 1;
            else next = i * (i-1) / 2 + a + 1;
            G[now].push_back(next);
            now = next;
        }
    }

    d.assign(size, 0);
    seen.assign(size, false);
    finished.assign(size, false);

    dfs(0);
    if (cycle) {
        cout << -1 << endl;
    } else {
        cout << d[0] << endl;
    }
}