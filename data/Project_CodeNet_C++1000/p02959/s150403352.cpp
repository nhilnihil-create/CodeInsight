#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, bef = 0;
  cin >> N;
  vector<int64_t> A(N + 1);
  for (int i = 0; i <= N; i++)
  {
    cin >> A.at(i);
  }
  bef = accumulate(A.begin(), A.end(), 0LL);
  for (int i = 0; i < N; i++)
  {
    int64_t b;
    cin >> b;
    A.at(i) -= b;
    if (A.at(i) >= 0)
      continue;
    b = abs(A.at(i));
    A.at(i) = 0;
    A.at(i + 1) -= b;
    if (A.at(i + 1) < 0)
      A.at(i + 1) = 0;
  }
  int64_t aft = accumulate(A.begin(), A.end(), 0LL);
  cout << bef - aft << endl;
}