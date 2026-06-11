#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int bfs(vector<string> field, pair<int, int> s_pos, pair<int, int> g_pos)
{
  int dirx[] = {1, 0};
  int diry[] = {0, 1};
  int R, C;
  int INF = INT32_MAX;
  R = field.size();
  C = field[0].size();

  vector<vector<int>> cost(R, vector<int>(C, INF));
  queue<pair<int, int>> pos_queue;
  if (field[0][0] == '.')
    cost[s_pos.first][s_pos.second] = 0;
  else
    cost[s_pos.first][s_pos.second] = 1;

  pos_queue.push(s_pos);

  while (pos_queue.size())
  {
    pair<int, int> pos = pos_queue.front();
    int pos_x = pos.first;
    int pos_y = pos.second;
    pos_queue.pop();
    rep(i, 2)
    {
      int next_x = pos_x + dirx[i];
      int next_y = pos_y + diry[i];

      if (0 <= next_x && next_x < R && 0 <= next_y && next_y < C)
      {
        int next_cost;
        if (field[pos_x][pos_y] == '.' && field[next_x][next_y] == '#')
          next_cost = cost[pos_x][pos_y] + 1;
        else
          next_cost = cost[pos_x][pos_y] + 0;

        if (cost[next_x][next_y] == INF)
        {
          pos_queue.push(make_pair(next_x, next_y));
        }
        cost[next_x][next_y] = min(cost[next_x][next_y], next_cost);
      }
    }
  }

  return cost[R - 1][C - 1];
}

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> s(H);
  rep(i, H)
  {
    cin >> s[i];
  }
  pair<int, int> start = make_pair(0, 0);
  pair<int, int> goal = make_pair(H - 1, W - 1);

  int ans = bfs(s, start, goal);
  cout << ans << endl;
  return 0;
}