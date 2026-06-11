#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(),x.end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int mod = 1e9+7;
const ll INF = 1e18;
const int MAX = 1e6;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct edge {int to, cost;}; // 辺
// vector<edge> graph[MAX]; // 隣接リスト
// bool visited[MAX]; // 訪問状況

int n, m; // 変数
ll a;
double b;

int main() {
// input
    cin >> a >> b;
// solve
// output
    cout << (a * (ll)(b * 100 + 0.001) / 100) << "\n";
}