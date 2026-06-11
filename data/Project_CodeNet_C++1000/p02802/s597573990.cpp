#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;
// const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// struct edge {int to, cost;};
// vector<edge> graph[MAX];
// bool visited[MAX];
// int dist[MAX];

int main() {
    // input
    int n, m;
    cin >> n >> m;
    // solve
    vector<bool> ac(n, false);
    vector<int> wa(n, 0);
    int cnt_ac = 0, cnt_wa = 0;
    rep(i, m) {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if (ac[p]) continue;
        if (s == "AC") {
            ac[p] = true;
            cnt_ac++;
            cnt_wa += wa[p];
        } else if (s == "WA") {
            wa[p]++;
        }
    }
    // output
    printf("%d %d\n", cnt_ac, cnt_wa);
}