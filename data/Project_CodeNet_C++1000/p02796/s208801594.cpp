#include <bits/stdc++.h>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  int N;
  cin >> N;

  int x[N], l[N];
  pair<int, int> A[N];

  for (int i = 0; i < N; i++)
  {
    cin >> x[i] >> l[i];
    A[i].first = x[i] + l[i];
    A[i].second = x[i] - l[i];
  }
  sort(A, A + N);
  int ans = 1;
  int tmp = A[0].first;

  for (int i = 1; i < N; i++)
  {
    if (tmp <= A[i].second)
    {
      ans++;
      tmp = A[i].first;
    }
  }
  cout << ans << endl;
}
