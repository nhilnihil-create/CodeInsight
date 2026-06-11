#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, ma = 0;
  cin >> N;
  vector<int64_t> X(N), Y(N);
  for (int i = 0; i < N; i++)
  {
    cin >> X.at(i) >> Y.at(i);
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (i == j)
        continue;
      int64_t p = X[j] - X[i], q = Y[j] - Y[i], cnt = 0;
      for (int k = 0; k < N; k++)
      {
        for (int l = 0; l < N; l++)
        {
          if (k == l)
            continue;
          if (X[k] + p == X[l] && Y[k] + q == Y[l])
            cnt++;
        }
      }
      ma = max(ma, cnt);
    }
  }
  cout << N - ma << endl;
}