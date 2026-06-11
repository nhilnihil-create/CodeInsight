#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    int n;
    cin >> n;
    vector<int> e(n-1);
    const int N = 100000;
    int color[N];
    rep(i,N) color[i] = i+1;
    // 辺の番号と次のノード
    vector<vector<P>> to(n);
    // ノードを訪れたか
    vector<bool> visited(n, false);
    int a, b;
    rep(i,n-1) {
        cin >> a >> b;
        a--; b--;
        to[a].emplace_back(i,b);
        to[b].emplace_back(i,a);
    }
    // ノードと前の辺の色
    queue<P> q;
    q.emplace(0, 0);
    int c_n, f_c, n_n, n_c;
    visited[0] = true;
    while (!q.empty()) {
        c_n = q.front().first;
        f_c = q.front().second;
        q.pop();
        int j = 0;
        rep(i,to[c_n].size()) {
            n_n = to[c_n][i].second;
            // 訪れとことがある場合はとばす
            if (visited[n_n]) {j--; continue;}
            // 色がかぶる場合は一つ色を増やす
            if (color[i+j] == f_c) j++;
            n_c = color[i+j];
            visited[n_n] = true;
            e[to[c_n][i].first] = n_c;
            q.emplace(n_n, n_c);
        }
    }
    int max_c = 0;
    rep(i,n-1) {
        max_c = max(max_c, e[i]);
    }
    cout << max_c << endl;
    rep(i,n-1) cout << e[i] << endl;
    
    return 0;
}