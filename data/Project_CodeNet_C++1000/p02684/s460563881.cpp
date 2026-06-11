#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int64_t N, K, per;
vector<int> to(MAXN);
vector<int> steps(MAXN, -1);

void dfs(int v, int step)
{
  if (steps[v] != -1)
  {
    per = step - steps[v];
    int64_t k = (K - steps[v]) % per;
    for (int i = 0; i < N; i++)
    {
      if (steps[i] == k + steps[v])
      {
        cout << i + 1 << endl;
      }
    }
    return;
  }
  if (step == K)
  {
    cout << v + 1 << endl;
    return;
  }
  steps[v] = step;
  dfs(to[v], step + 1);
}

int main()
{
  cin >> N >> K;
  for (int i = 0; i < N; i++)
  {
    cin >> to[i];
    to[i]--;
  }
  dfs(0, 0);
}