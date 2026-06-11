#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;

int n, q; 
ll score[200010];

vector<vector<ll>> g(200010);

void dfs(int i, int p) {
    for (ll x:g[i]) {
        if (x == p) continue;
        score[x] += score[i];
        dfs(x,i);
    }
}

int main() {
    cin >> n >> q;
    rep(i, n-1) {
       int a, b; cin >> a >> b;
       g[a-1].push_back(b-1);
       g[b-1].push_back(a-1);
    }
    rep(i,q) {
        int p, q; cin >> p >> q;
        score[p-1] += q;
    }
    dfs(0,0);
    rep(i,n) {
        cout << score[i] << " ";
    }
    cout << endl;
    return 0;
}