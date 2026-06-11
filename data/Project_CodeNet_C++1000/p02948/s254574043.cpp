#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main()
{
  int N, M;
  cin >> N >> M;
  priority_queue<P, vector<P>, greater<P>> pq;
  priority_queue<P> usable;
  for (int i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    pq.emplace(a, b);
  }
  int64_t ans = 0;
  for (int d = M - 1; d >= 0; d--)
  {
    while (pq.size() && pq.top().first + d <= M)
    {
      usable.emplace(pq.top().second, pq.top().first);
      pq.pop();
    }
    if (usable.size())
    {
      ans += usable.top().first;
      usable.pop();
    }
  }
  cout << ans << endl;
}