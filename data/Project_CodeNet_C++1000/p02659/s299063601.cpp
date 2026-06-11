#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t A;
  string S;
  cin >> A >> S;
  int64_t B = 0;
  for (int i = 0; i < S.size(); i++)
  {
    if (S.at(i) == '.')
      continue;
    int j = S.at(i) - '0';
    B = 10 * B + j;
  }
  cout << A * B / 100 << endl;
}