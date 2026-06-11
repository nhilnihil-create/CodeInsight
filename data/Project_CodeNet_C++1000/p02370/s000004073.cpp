#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<pair<int, int>, int> PP;
const ll INFL = 1LL << 60;
const ll MOD = 1000000007;
const int INF = 1000000000;
const int MAX = 300000;
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }

//------------------------------------------------------------------------------------------------------------------------------

vector<vector<int>> G;
vector<int> ans;
bool visit[10000];
void dfs(int v) {
    visit[v] = 1;
    for (auto nv : G[v]) {
        if (visit[nv]) {
            continue;
        }
        dfs(nv);
    }
    ans.push_back(v);
}

int main(void) {
    int V, E;
    cin >> V >> E;
    G.resize(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }
    for (int i = 0; i < V; i++) {
        if (!visit[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}
