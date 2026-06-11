#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fi first
#define sec second
#define pr priority_queue
#define ump  unordered_map
#define prg priority_queue<ll, vec<ll> ,greater<ll> >
#define pb  push_back;
//parent finding
ll find(vector<ll> &v, ll n)
{
  if (v[n] == n)
    return n;
  return v[n] = find(v, v[n]);
}
bool is(ll x, ll y, ll n, ll m)
{
  if (x >= 0 && x < n && y >= 0 && y < m)
    return true;
  return false;
}
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
void bfs(vector<vector<char> > &vec, ll st1, ll st2, vector<vector<ll> > &dist)
{
  ll n = vec.size(), m = vec[0].size();
  pair<ll, ll> p;
  p.fi = st1; p.sec = st2;
  dist[st1][st2] = 0;
  deque<pair<ll, ll> > dq;
  dq.push_back(p);
  while (!dq.empty())
  {
    pair<ll, ll> p1;
    p1.fi = dq.front().fi; p1.sec = dq.front().sec;
    dq.pop_front();
    for (ll i = 0; i < 4; i++)
    {
      ll x = p1.fi + dx[i], y = p1.sec + dy[i];
      if (is(x, y, n, m) && vec[x][y] != '#')
      {
        if (dist[x][y] > dist[p1.fi][p1.sec])
        {
          dist[x][y] = dist[p1.fi][p1.sec];
          dq.push_front({x, y});
        }
      }
    }
    for (ll i = p1.fi - 2; i <= p1.fi + 2; i++)
    {
      for (ll j = p1.sec - 2; j <= p1.sec + 2; j++)
      {
        if (is(i, j, n, m) && vec[i][j] != '#')
        {
          if (dist[i][j] > dist[p1.fi][p1.sec] + 1)
          {
            dist[i][j] = dist[p1.fi][p1.sec] + 1;
            dq.push_back({i, j});
          }
        }
      }
    }
  }
  return ;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, m, k; cin >> n >> m >> k;
  map<ll, ll> mp1, mp2;
  set<pair<ll, ll> > st;
  for (ll i = 0; i < k; i++)
  {
    ll x, y; cin >> x >> y;
    st.insert({x, y});
    mp1[x]++;
    mp2[y]++;
  }
  ll m1 = -1, m2 = -1;
  vector<ll> c1, c2;
  for (auto x : mp1)
    m1 = max(m1, x.sec);
  for (auto x : mp2)
    m2 = max(m2, x.sec);
  for (auto x : mp1)
    if (x.sec == m1)
      c1.push_back(x.fi);
  for (auto x : mp2)
    if (x.sec == m2)
      c2.push_back(x.fi);
  ll sz1 = c1.size(), sz2 = c2.size();
  ll ans = m1 + m2 - 1;
  for (ll i = 0; i < sz1; i++)
  {
    ll f = 0;
    for (ll j = 0; j < sz2; j++)
    {
      if (st.find({c1[i], c2[j]}) == st.end())
      {
        ans++;
        f = 1;
        break;
      }
    }
    if (f) break;
  }
  cout << ans << "\n";
  return 0;
}