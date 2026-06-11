#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, C;
  cin >> N >> K >> C;
  vector<bool> vb(N);
  vector<int> vl(N, -1), vr(N, -1);
  char c;
  for (int i = 0; i < N; i++)
  {
    cin >> c;
    vb[i] = (c == 'o');
  }
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    if (cnt >= K)
    {
      break;
    }
    if (!vb[i])
      continue;
    vl[i] = ++cnt;
    i += C;
  }
  int k = 0;
  for (int i = N - 1; i >= 0; i--)
  {
    if (k >= K)
    {
      break;
    }
    if (!vb[i])
      continue;
    k++;
    vr[i] = (cnt + 1) - k;
    i -= C;
  }
  queue<int> ans;
  for (int i = 0; i < N; i++)
  {
    if (vl[i] > 0 && vl[i] == vr[i])
    {
      ans.push(i + 1);
    }
  }
  while (ans.size())
  {
    cout << ans.front() << endl;
    ans.pop();
  }
}