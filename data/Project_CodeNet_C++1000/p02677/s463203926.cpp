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
const double pi = 3.14159265358979;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct edge {int to, cost;}; // 辺
// vector<edge> graph[MAX]; // 隣接リスト
// bool visit[MAX]; // 訪問状況

int a, b; // 変数
double h, m;

int main() {
// input
    cin >> a >> b;
    cin >> h >> m;
// solve
    double longer = h * (2 * pi / 12) + m * (2 * pi / 12 / 60);
    double shorter = m * (2 * pi / 60);
    double theta = longer - shorter;
    double c = sqrt(a * a + b * b - 2 * a * b * cos(theta));
// output
    printf("%.10f\n", c);
}