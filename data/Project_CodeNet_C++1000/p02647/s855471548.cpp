#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < K; i++)
  {
    vector<int> B(N, 0);
    for (int j = 0; j < N; j++)
    {
      B.at(max(0, j - A.at(j)))++;
      if (j + A.at(j) + 1 <= N - 1)
        B.at(j + A.at(j) + 1)--;
    }
    int cnt = 0;
    for (int j = 1; j < N; j++)
    {
      B.at(j) += B.at(j - 1);
      if (B.at(j) == N)
        cnt++;
    }
    if (B.at(0) == N)
      cnt++;
    A = B;
    if (cnt == N)
      break;
  }
  for (int i = 0; i < N; i++)
  {
    if (i)
      cout << ' ';
    cout << A.at(i);
  }
  cout << endl;
}
