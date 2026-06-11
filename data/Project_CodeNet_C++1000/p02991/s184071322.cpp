#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)

void chmax(ll& a, ll b) { a = max(a, b); }
void chmin(ll& a, ll b) { a = min(a, b); }

using P = pair<int, int>;

const int MAX_N = 1e5+5;
const int INF = 1001001001;

vector<int> a, ans;
int dp[MAX_N][3];

ll modnum = 1e9+7;

using Graph = vector<vector<int>>;
Graph to(MAX_N);

void dfs(int u, int count=0, int rem=2) {
    if(rem == -1) {
        count++;
        rem = 2;
    }

    if(dp[u][2-rem] <= count) {
        return;
    } else {
        dp[u][2-rem] = count;
    }

    for(auto v : to[u]) {
        dfs(v, count, rem-1);
    }

}

int main() {
    int n,m; cin >> n >> m;
    rep(i, m) {
        int u,v; cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
    }
    int s,t; cin >> s >> t;
    s--; t--;

    rep(i, MAX_N) rep(j,3) dp[i][j] = INF;
    queue<P> que;
    que.emplace(s, 0);
    while(!que.empty()) {
        P p = que.front();
        que.pop();
        if(dp[p.first][p.second%3] > p.second/3) {
            dp[p.first][p.second%3] = p.second/3;
            for(auto u : to[p.first]) {
                que.emplace(u, p.second+1);
            }
        }
    }

    if(dp[t][0] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[t][0] << endl;
    }

    return 0;
}
