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
    int n, k;
    cin >> n >> k;
    int h[n];
    rep(i, n) {
        cin >> h[i];
    }
    // solve
    sort(h, h+n, greater<int>());
    ll cnt = 0;
    rep(i, n) {
        if (k > 0) k--;
        else cnt += h[i];
    }
    // output
    cout << cnt << endl;
}