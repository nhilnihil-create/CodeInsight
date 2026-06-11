#include <iostream>
#include <vector>
using namespace std;

int n;
void dfs(string &s, char Max)
{
  if (s.length() == n)
  {
    cout << s << endl;
    return;
  }
  for (char c = 'a'; c <= Max; ++c)
  {
    s.push_back(c);
    dfs(s, Max);
    s.pop_back();
  }
  s.push_back(Max + 1);
  dfs(s, Max + 1);
  s.pop_back();
}

int main()
{
  cin >> n;
  string s;
  dfs(s, 'a' - 1);
  return 0;
}
