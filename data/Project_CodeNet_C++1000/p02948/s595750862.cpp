#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, M, a, b, ans = 0;
  cin >> N >> M;
  priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> ab;
  for (int i = 0; i < N; i++)
  {
    cin >> a >> b;
    if (a <= M)
      ab.push(make_pair(a, b));
  }
  priority_queue<int64_t> pq;
  for (int d = 1; d <= M; d++) // d日前
  {
    while (!ab.empty() && ab.top().first <= d)
    {
      pq.push(ab.top().second);
      ab.pop();
    }
    if (!pq.empty())
    {
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans << endl;
}