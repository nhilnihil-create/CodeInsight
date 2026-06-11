#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main(){

    int h, w;
    cin >> h >> w;
    V<string> s(h);
    rep(i, h)cin >> s[i];

    deque<P> dq;
    dq.push_front(P(0, 0));
    vvi dist(h, vi(w, INF));
    dist[0][0] = s[0][0] == '#' ? 1 : 0;

    while (!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;dq.pop_front();
        vi dy = { 0,1 };
        vi dx = { 1,0 };
        rep(i, 2) {
            int ey = y + dy[i];
            int ex = x + dx[i];
            if (ey < 0 || h <= ey || ex < 0 || w <= ex)continue;
            int d = 0;
            if (s[y][x] == '.' && s[ey][ex] == '#')d = 1;
            if (dist[ey][ex] <= dist[y][x] + d)continue;
            dist[ey][ex] = dist[y][x] + d;
            if (d)dq.push_back(P(ey, ex));
            else dq.push_front(P(ey, ex));
        }
    }

    cout << dist[h - 1][w - 1] << endl;

 }