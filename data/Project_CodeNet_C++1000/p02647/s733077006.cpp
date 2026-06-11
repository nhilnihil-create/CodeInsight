#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, d;
  cin >> N >> K;
  vector<int64_t> D(N);
  vector<int64_t> S(N + 1, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> D.at(i);
  }
  for (int k = 0; k < K; k++)
  {
    for (int i = 0; i < N; i++)
    {
      S.at(max((int64_t)(0), (int64_t)(i - D[i])))++;
      S.at(min(N, (int64_t)(i + D[i] + 1)))--;
    }
    int64_t cnt = 0; // Nの数
    for (int i = 0; i < N; i++)
    {
      S[i + 1] += S[i];
      D[i] = S[i];
      S[i] = 0;
      if (D[i] == N)
        cnt++;
    }
    S[N] = 0;
    if (cnt == N)
    {
      break;
    }
  }
  for (int i = 0; i < N; i++)
  {
    cout << D[i];
    if (i < N - 1)
      cout << ' ';
  }
  cout << endl;
}