#include <bits/stdc++.h>
using namespace std;
int64_t N;
string S;

bool f(int len)
{
  for (int l = 0; l < N - (len - 1); l++)
  {
    string s1 = S.substr(l, len);
    for (int l2 = l + len; l2 < N - (len - 1); l2++)
    {
      if (s1[0] != S[l2])
        continue;
      if (s1 == S.substr(l2, len))
        return true;
    }
  }
  return false;
}

int main()
{
  cin >> N >> S;
  vector<int> Count(26, 0);
  int mi = 0;
  for (int i = 0; i < N; i++)
  {
    int j = S.at(i) - 'a';
    if (Count.at(j))
      mi = 1;
    Count.at(j)++;
  }
  int left = 0, right = N;
  while (right - left > 1)
  {
    int mid = (right + left) / 2;
    if (f(mid))
      left = mid;
    else
      right = mid;
  }
  cout << max(mi, left) << endl;
}
