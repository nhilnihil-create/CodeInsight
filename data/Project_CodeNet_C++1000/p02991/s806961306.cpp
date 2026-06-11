#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

struct Data {
    int p, len, state;
};

const int INF = 1e9;

int main() {
    int n, m; cin >> n >> m;
    vector< vector<int> > graphlist(n, vector<int>());
    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        graphlist[u].emplace_back(v);
    }
    int s, t; cin >> s >> t;
    s--; t--;
    vector< vector<int> > graph(3, vector<int>(n, INF));

    graph[0][s] = 0;
    Data first;
    first.p = s; first.len = 0; first.state = 0;
    queue<Data> que;
    que.push(first);

    while(!que.empty()) {
        Data now = que.front();
        que.pop();
        for(int i = 0; i < (int)graphlist[now.p].size(); ++i) {
            int np = graphlist[now.p][i];
            int nlen = now.len+1;
            int nstate = nlen%3;
            if(graph[nstate][np] > nlen) {
                graph[nstate][np] = nlen;
                Data next;
                next.p = np; next.len = nlen; next.state = nstate;
                que.push(next);
            }
        }
    }

    if(graph[0][t] == 1e9) cout << -1 << endl;
    else cout << graph[0][t]/3 << endl;
}