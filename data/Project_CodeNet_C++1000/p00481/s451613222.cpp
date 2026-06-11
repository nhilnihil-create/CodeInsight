#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned __int128 HASH;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll,int> plli;
typedef pair<double, int> pdbi;
typedef pair<int,pii> pipii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vector<int>> mat;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

const ll hmod1 = 999999937;
const ll hmod2 = 1000000000 + 9;
const ll INF = 1<<30;
const ll mod = 10000;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

//#define int long long
#define addm(X, Y) ((X) = ((X) + (Y) % mod) % mod)

int h, w, n;
char g[1000 + 5][1000 + 5];
int sx, sy;

bool check(int y, int x) {
    if (0 <= y && y < h && 0 <= x && x < w) {
        if (g[y][x] != 'X') return true;
    }
    return false;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w >> n;
    rep(i, h)rep(j, w) {
        cin >> g[i][j];
        if (g[i][j] == 'S') {
            sy = i;
            sx = j;
        }
    }
    int ans = 0;
    int dist[h][w] = {};
    bool visited[h][w] = {};
    int nowy = sy, nowx = sx;
    rep(i, n) {
        rep(i, h)rep(j, w) {
            dist[i][j] = INF;
            visited[i][j] = false;
        }
        queue<pair<int, int>> q;
        q.push({nowy, nowx});
        dist[nowy][nowx] = 0;
        visited[nowy][nowx] = true;
        while (q.size() != 0) {
            pair<int, int> now = q.front(); q.pop();
            rep(j, 4) {
                int ny = now.fi + dy4[j];
                int nx = now.se + dx4[j];
                if (!check(ny, nx) || visited[ny][nx]) continue;
                q.push({ny, nx});
                visited[ny][nx] = true;
                dist[ny][nx] = dist[now.fi][now.se] + 1;
                if (g[ny][nx] - '0' == i + 1) {
                    ans += dist[ny][nx];
                    nowy = ny;
                    nowx = nx;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}