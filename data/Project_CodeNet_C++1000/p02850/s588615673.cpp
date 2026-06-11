#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;

    vector<vector<int> > G(N);
    map<pii, int> mp;
    int u, v;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        mp[pii(u, v)] = i;
        mp[pii(v, u)] = i;
    }

    vector<int> color(N - 1);
    vector<int> visited(N);
    queue<pii> q;
    q.push(pii(0, -1));
    visited[0] = 1;
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        int from = p.first, preColor= p.second;
        for (int i = 0, curColor = 1; i < G[from].size(); i++) {
            int to = G[from][i];
            if (visited[to]) continue;
            visited[to] = 1;
            if (curColor == preColor) curColor++;
            color[mp[pii(from, to)]] = curColor;
            q.push(pii(to, curColor));
            curColor++;
        }
    }

    cout << *max_element(color.begin(), color.end()) << '\n';
    for (int c : color) cout << c << '\n';
}
