#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MOD 1000000007

int main()
{
  ll n;
  cin >> n;
  vector<ll> degs(n + 1, 0);
  vector<set<ll>> edges(n + 1, set<ll>{}); // ノードに何番目のedgeがつながっているか

  for (auto i = 0; i < n - 1; i++)
  {
    ll a, b;
    cin >> a >> b;
    edges[a].insert(i + 1);
    edges[b].insert(i + 1);
  }

  ll max_degree = 0;
  for (auto i = 1; i <= n; i++)
  {
    max_degree = max((long long)(edges[i].size()), max_degree);
  }

  // 色がついていないものを0とする
  vector<ll> colors(n, 0);
  set<ll> visited = {};
  queue<ll> q{};

  for (auto i = 1; i <= n; i++)
  {
    auto edge_list = edges[i]; // nodeにあるedges.
    set<ll> used_color = {};
    for (auto edge : edge_list)
    {
      used_color.insert(colors[edge]);
    }

    ll color_start = 1;
    for (auto edge : edge_list)
    {
      if (colors[edge] == 0)
      {
        for (auto j = color_start; j <= max_degree; j++)
        {
          if (used_color.count(j) == 0)
          {
            colors[edge] = j;
            used_color.insert(j);
            color_start = j + 1;
            break;
          }
        }
      }
    }
  }

  cout << max_degree << endl;
  for (auto i = 1; i <= n - 1; i++)
  {
    cout << colors[i] << endl;
  }

  return 0;
}
