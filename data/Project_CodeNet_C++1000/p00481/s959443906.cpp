#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
 
/* short */
#define pb push_back
#define print(x) cout << x << '\n'
 
/* REPmacro */
#define REPS(i, a, n) for (int i = (a); i < (n); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = 1; i <= (n); i++)
#define DEPS(i, a, n) for (int i = (a); i >= n; i--)
#define DEP(i, n) for (int i = (n); i >= 0; i--)

/* typedef */
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

/* const */
const int INF = INT_MAX;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

/* func */
inline bool is_uruu(int y) {return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));}

int H, W, N;
char field[1024][1024];

int bfs(int sx, int sy, int gx, int gy)
{
  int res[1024][1024];
  memset(res, -1, sizeof(res));
  queue<pii> Q;
  Q.push(pii(sx, sy));
  res[sy][sx] = 0;

  for (; !Q.empty();){
    int x = Q.front().first, y = Q.front().second; Q.pop();
    //cout << "debug: x " << x << " y " << y << endl;
    if (x == gx && y == gy)  break;
    REP(i, 4){
      int mx = x + dx[i], my = y + dy[i];
      if (mx < 0 || my < 0 || mx >= W || my >= H) continue;
      if (field[my][mx] != 'X' && res[my][mx] == -1){
        Q.push(pii(mx, my));
        res[my][mx] = res[y][x] + 1;
      }
    }
  }

  return (res[gy][gx]);
}

signed main()
{
  ios::sync_with_stdio(false);
  pii st;
  pii fac[10];

  cin >> H >> W >> N;
  REP(i, H){
    REP(j, W){
      cin >> field[i][j];
      if (field[i][j] == 'S') st = pii(j, i);
      if (isdigit(field[i][j])) fac[field[i][j] - '0'] = pii(j, i);
    }
  }

  int ans = bfs(st.first, st.second, fac[1].first, fac[1].second);
  REPS(i, 2, N + 1){
    ans += bfs(fac[i - 1].first, fac[i - 1].second, fac[i].first, fac[i].second);
  }
  print(ans);

  return (0);
}