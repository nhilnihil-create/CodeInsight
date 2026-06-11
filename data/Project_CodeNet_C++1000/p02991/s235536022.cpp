#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
void YESNO(bool), YesNo(bool);
template <class T1, class T2>
bool chmin(T1 &l, const T2 &r);
template <class T1, class T2>
bool chmax(T1 &l, const T2 &r);
lli idx(int u, int d)
{
  return 3 * u + d;
}
struct dijkstra
{
  using lli = long long int;
  vector<vector<pair<lli, lli>>> e;
  int n;
  lli inf = 1e18;
  dijkstra(int n) : n(n)
  {
    e.resize(n);
  }
  void add(int a, int b, lli c)
  {
    e[a].push_back(make_pair(b, c));
  }
  void biadd(int a, int b, lli c)
  {
    add(a, b, c);
    add(b, a, c);
  }
  vector<lli> get(int s)
  {
    vector<lli> dist(n, inf);
    dist[s] = 0;
    using p = pair<lli, lli>;
    priority_queue<p, vector<p>, greater<p>> que;
    que.push(make_pair(0, s));
    while (!que.empty())
    {
      lli d = que.top().first;
      lli cur = que.top().second;
      que.pop();
      if (dist[cur] < d)
        continue;
      dist[cur] = d;
      for (auto s : e[cur])
      {
        lli wei = s.second;
        lli to = s.first;
        if (dist[to] > dist[cur] + wei)
        {
          dist[to] = dist[cur] + wei;
          que.push(make_pair(dist[cur] + wei, to));
        }
      }
    }
    return dist;
  }
};
void solve(long long N, long long M, std::vector<long long> u,
           std::vector<long long> v, long long S, long long T)
{
  dijkstra dij(3 * N);
  rep(i, M) v[i]--, u[i]--;
  rep(i, M)
  {
    rep(j, 3)
    {
      dij.add(idx(u[i], j), idx(v[i], (j + 1) % 3), 1);
      //      dij.add(idx(v[i], j), idx(u[i], (j + 1) % 3), 1);
    }
  }
  S--, T--;
  auto dis = dij.get(idx(S, 0))[idx(T, 0)];
  cout << (dis < 1e9 ? dis / 3 : -1) << endl;
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> u(M);
  std::vector<long long> v(M);
  for (int i = 0; i < M; i++)
  {
    scanf("%lld", &u[i]);
    scanf("%lld", &v[i]);
  }
  long long S;
  scanf("%lld", &S);
  long long T;
  scanf("%lld", &T);
  solve(N, M, std::move(u), std::move(v), S, T);
  return 0;
}

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2>
bool chmin(T1 &l, const T2 &r)
{
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2>
bool chmax(T1 &l, const T2 &r)
{
  return (l < r) ? (l = r, true) : false;
}
