#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cassert>
using namespace std;

#define GET_ARG(a,b,c,F,...) F
#define REP3(i,s,e) for (i = s; i <= e; i++)
#define REP2(i,n) REP3 (i,0,(int)(n)-1)
#define REP(...) GET_ARG (__VA_ARGS__,REP3,REP2) (__VA_ARGS__)
#define RREP3(i,s,e) for (i = s; i >= e; i--)
#define RREP2(i,n) RREP3 (i,(int)(n)-1,0)
#define RREP(...) GET_ARG (__VA_ARGS__,RREP3,RREP2) (__VA_ARGS__)
#define DEBUG(x) cerr << #x ": " << x << endl

typedef long long ll;

constexpr int INF = 1e8;
constexpr int MOD = 1e9+7;

string field[100];
bool used[100][100];
int dxy[] = {0,1,0,-1};
int h, w;

void dfs(int y, int x) {
    if (used[y][x]) return;
    used[y][x] = true;
    int i;
    REP (i,4) {
        int ny = y + dxy[i];
        int nx = x + dxy[(i+1)%4];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        if (field[ny][nx] == field[y][x]) dfs(ny,nx);
    }
}

int main(void) {
    while (true) {
        int i, j;
        cin >> h >> w;
        if (h == 0 && w == 0) break;
        REP (i,h) cin >> field[i];

        REP (i,h) REP (j,w) used[i][j] = false;
        int ans = 0;
        REP (i,h) REP (j,w) if (!used[i][j]) {
            dfs(i,j);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}