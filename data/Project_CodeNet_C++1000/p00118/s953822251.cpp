// ?????¬???????????¬??????

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

int H, W;
char board[110][110];
bool visited[110][110];

signed main() {
    while(cin >> H >> W, H || W) {
        rep(i,0,H) rep(j,0,W) cin >> board[i][j];
        memset(visited, false, sizeof(visited));

        int ans = 0;
        rep(i,0,H) rep(j,0,W) {
            if(visited[i][j]) continue;
            visited[i][j] = true;
            ans++;

            queue<pii> que;
            que.push(make_pair(i, j));

            while(!que.empty()) {
                pii t = que.front(); que.pop();
                int x = t.first, y = t.second;
                rep(k,0,4) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                    if(board[x][y] != board[nx][ny]) continue;
                    if(visited[nx][ny]) continue;

                    visited[nx][ny] = true;
                    que.push(make_pair(nx, ny));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}