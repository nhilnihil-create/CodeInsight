#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, ans = 1;
  cin >> n;
  vector<char> s;
  char c;
  cin >> c;
  s.push_back(c);
  for (int i = 1; i < n; i++)
  {
    cin >> c;
    if (c != s.at(i - 1))
    {
      ans++;
    }
    s.push_back(c);
  }
  cout << ans << endl;
}