#include <bits/stdc++.h>
using namespace std;
const int64_t MAXN = 100010;
const int64_t MOD = 1000000007;
vector<vector<int64_t>> Graph(MAXN);
vector<int64_t> Colors(MAXN, -1);

int main()
{
  int64_t N, K, a, b, ans = 1;
  cin >> N >> K;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> a >> b;
    a--, b--;
    Graph.at(a).push_back(b);
    Graph.at(b).push_back(a);
  }
  queue<int64_t> Q;
  Q.push(0);
  Colors.at(0) = K;
  while (Q.size())
  {
    int64_t cur = Q.front();
    Q.pop();
    int64_t cnt = 1;
    if (cur)
      cnt++;
    for (auto next : Graph.at(cur))
    {
      if (Colors.at(next) >= 0)
        continue;
      if (K - cnt <= 0)
      {
        cout << 0 << endl;
        return 0;
      }
      Colors.at(next) = (K - cnt);
      Q.push(next);
      cnt++;
    }
  }
  for (int i = 0; i < N; i++)
  {
    (ans *= Colors.at(i)) %= MOD;
  }
  cout << ans << endl;
}
