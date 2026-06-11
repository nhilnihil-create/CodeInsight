#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= 9; j++)
    {
      s.insert(i * j);
    }
  }
  if (s.count(n))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}