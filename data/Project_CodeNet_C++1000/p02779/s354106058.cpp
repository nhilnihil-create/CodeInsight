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
    int n;
    cin >> n;
    int a[n];
    set<int> s;
    bool flag = true;
    rep(i, n) {
        cin >> a[i];
        if (s.count(a[i])) flag = false;
        else s.insert(a[i]);
    }
    // output
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}